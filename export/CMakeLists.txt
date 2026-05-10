target_include_directories(
    just-harmonizer
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/rnbo"
        "${CMAKE_CURRENT_SOURCE_DIR}/rnbo/common"
)

target_sources(
    just-harmonizer
    PRIVATE
        rnbo_source.cpp
        rnbo/RNBO.cpp
)