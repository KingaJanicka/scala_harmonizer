# ==============================================================================
#
#  Copyright 2022 Suzuki Kengo
#
#  JR-Granular is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  JR-Granular is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with JR-Granular. If not, see <http://www.gnu.org/licenses/>.
#
# ==============================================================================

cmake_minimum_required(VERSION 3.27)

# These variables should be set before the first project() command is called.
# Additionally, they should be set as cache variables so that their values can be overridden.
# References:
# - https://cmake.org/cmake/help/v3.27/variable/CMAKE_OSX_ARCHITECTURES.html
# - https://cmake.org/cmake/help/v3.27/variable/CMAKE_OSX_DEPLOYMENT_TARGET.html
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "Build architectures for macOS")
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.12" CACHE STRING "Minimum macOS version required")

project(just-harmonizer VERSION 1.0.4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(TARGET_NAME "${PROJECT_NAME}")

set(PLUGIN_FORMATS VST3 AU Standalone)

if(CMAKE_SYSTEM_NAME STREQUAL "iOS")
    # The AUv3 extension needs a container app to be installable at all;
    # JUCE embeds the extension into the Standalone app's bundle automatically
    # when both formats are present.
    set(PLUGIN_FORMATS Standalone AUv3)
endif()

if(DEFINED ENV{CI})
    list(REMOVE_ITEM PLUGIN_FORMATS Standalone)
endif()

add_subdirectory(lib/JUCE)

set(IOS_PLUGIN_ARGS "")
if(CMAKE_SYSTEM_NAME STREQUAL "iOS")
    # "1,2" targets both iPhone and iPad; use "2" to restrict to iPad only.
    set(IOS_PLUGIN_ARGS TARGETED_DEVICE_FAMILY "1,2")
endif()

juce_add_plugin(${TARGET_NAME}
    COMPANY_NAME "Kinga"
    COMPANY_WEBSITE "https://kinga.dev"
    COMPANY_EMAIL "hi@kinga.dev"
    BUNDLE_ID "dev.kinga.${PROJECT_NAME}"
    PLUGIN_MANUFACTURER_CODE "Knga"
    PLUGIN_CODE "JSTH"
    FORMATS ${PLUGIN_FORMATS}
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_NAME "Just Harmonizer"
    ${IOS_PLUGIN_ARGS}
)

add_subdirectory(export)
add_subdirectory(src)

target_compile_definitions(${TARGET_NAME} PUBLIC JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 JUCE_VST3_CAN_REPLACE_VST2=0)

juce_add_binary_data(binary_data SOURCES res/UbuntuRegular.ttf)

target_link_libraries(
    ${TARGET_NAME}
    PRIVATE
        binary_data
        juce::juce_audio_utils
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# The desktop VST3/AU targets, pluginval, Developer ID codesigning, and CPack
# packaging below don't apply to the iOS AUv3 build (no VST3/AU targets exist,
# and iOS app-extension signing is handled by Xcode's automatic signing instead).
if(NOT CMAKE_SYSTEM_NAME STREQUAL "iOS")
    enable_testing()
    include(Pluginval)
    add_pluginval_tests(${TARGET_NAME}_VST3)

    if(DEFINED ENV{CI})
        include(Codesign)
        codesign_plugins(${TARGET_NAME})
    endif()

    if(APPLE)
        install(TARGETS ${TARGET_NAME}_VST3 LIBRARY DESTINATION "VST3" COMPONENT VST3)
        install(TARGETS ${TARGET_NAME}_AU LIBRARY DESTINATION "Components" COMPONENT AU)
    elseif(WIN32)
        install(TARGETS ${TARGET_NAME}_VST3 LIBRARY DESTINATION "." COMPONENT VST3)
    endif()

    set(PACKAGE_NAME "just-harmonizer")
    set(PACKAGE_DIRECTORY "${CMAKE_SOURCE_DIR}/dist/just-harmonizer")
    if(APPLE)
        set(PACKAGE_FILE_NAME "mac_${PACKAGE_NAME}")
    elseif(WIN32)
        set(PACKAGE_FILE_NAME "win_${PACKAGE_NAME}")
    endif()
    get_target_property(vendor ${TARGET_NAME} JUCE_COMPANY_NAME)
    get_target_property(contact ${TARGET_NAME} JUCE_COMPANY_EMAIL)
    set(CPACK_PACKAGE_NAME "${PACKAGE_NAME}")
    set(CPACK_PACKAGE_DIRECTORY "${PACKAGE_DIRECTORY}")
    set(CPACK_PACKAGE_FILE_NAME "${PACKAGE_FILE_NAME}")
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "This is ${PACKAGE_FILE_NAME} package.")
    set(CPACK_PACKAGE_VENDOR "${vendor}")
    set(CPACK_PACKAGE_CONTACT "${contact}")
    set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
    set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
    set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
    set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/res/license.txt")
    set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/res/readme.txt")
    set(CPACK_VERBATIM_VARIABLES TRUE)

    if(APPLE)
        set(CPACK_GENERATOR productbuild)
        set(CPACK_COMPONENTS_ALL "VST3" "AU")
        set(CPACK_PACKAGING_INSTALL_PREFIX "/Library/Audio/Plug-Ins")
        set(CPACK_PRODUCTBUILD_IDENTITY_NAME "Developer ID Installer")
        set(CPACK_PRODUCTBUILD_RESOURCES_DIR "${CMAKE_SOURCE_DIR}/res")
        set(CPACK_PRODUCTBUILD_BACKGROUND "background-light.png")
        set(CPACK_PRODUCTBUILD_BACKGROUND_DARKAQUA "background-dark.png")
    elseif(WIN32)
        set(CPACK_GENERATOR INNOSETUP)
        set(CPACK_INSTALL_CMAKE_PROJECTS "${CMAKE_CURRENT_BINARY_DIR};${PROJECT_NAME};VST3;/")
        set(CPACK_PACKAGE_INSTALL_DIRECTORY ".")
        set(CPACK_INNOSETUP_INSTALL_ROOT "{commoncf64}/VST3")
        set(CPACK_INNOSETUP_ARCHITECTURE x64)
        set(CPACK_INNOSETUP_ALLOW_CUSTOM_DIRECTORY ON)
        set(CPACK_INNOSETUP_USE_MODERN_WIZARD ON)
        set(CPACK_INNOSETUP_SETUP_Uninstallable no)
        set(CPACK_INNOSETUP_SETUP_UsePreviousAppDir no)
        set(CPACK_INNOSETUP_SETUP_DirExistsWarning no)
        set(CPACK_INNOSETUP_SETUP_AppendDefaultDirName no)
    endif()

    include(CPack)

    if(APPLE)
        cpack_add_component(${TARGET_NAME}_VST3 DISPLAY_NAME "VST3" DESCRIPTION "VST3 plugin" INSTALL_TYPES full)
        cpack_add_component(${TARGET_NAME}_AU DISPLAY_NAME "AU" DESCRIPTION "AU plugin" INSTALL_TYPES full)
        cpack_add_install_type(full)
    endif()

    include(EnvCI)
endif()
