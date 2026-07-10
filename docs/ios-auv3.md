# Building and Running the AUv3 on iPad

This project can build an AUv3 (Audio Unit v3) target for iOS/iPadOS via the
`ios-auv3` CMake preset, in addition to the desktop VST3/AU/Standalone build.
This document covers everything needed to build, sign, and install it on a
physical iPad from the command line, plus the gotchas encountered getting it
working the first time.

## Prerequisites (one-time setup)

1. **Install full Xcode.app** from the App Store — the Command Line Tools
   alone don't include the iOS SDK or code-signing tools. Point the toolchain
   at it:
   ```
   sudo xcode-select -s /Applications/Xcode.app/Contents/Developer
   ```
2. **Sign in to your Apple ID in Xcode**: Xcode → Settings → Accounts → **+**.
   A free Apple ID works for on-device testing (apps expire after 7 days —
   see below); no paid Developer Program membership is required.
3. **Get your Team ID.** Once Xcode has created an "Apple Development"
   certificate for your account, extract it from the certificate rather than
   hunting through the Accounts UI (the Team ID is easy to miss there):
   ```
   security find-certificate -a -c "Apple Development" -p ~/Library/Keychains/login.keychain-db | openssl x509 -noout -subject
   ```
   Look for `OU=XXXXXXXXXX` in the output. If this returns nothing, no cert
   exists yet — go to Xcode → Settings → Accounts → your Apple ID → **Manage
   Certificates...** → **+** → **Apple Development**, then retry.
4. **Enable Developer Mode on the iPad** (required on iOS/iPadOS 16+, and the
   toggle doesn't even exist in Settings until triggered once):
   - Connect the iPad, unlock it, and open **Xcode → Window → Devices and
     Simulators** (⇧⌘2). Select the iPad and let it finish pairing.
   - After pairing, check **Settings → Privacy & Security → Developer Mode**
     on the iPad. If it's not there yet, a throwaway build/install attempt
     (even one that fails) is usually enough to make it appear.
   - Toggle it on → iPad restarts → confirm **"Turn On"** in the dialog after
     unlocking.
5. **Get the iPad's UDID** from the same Devices and Simulators panel: click
   the device, right-click (or select) the **Identifier** field and copy it
   directly from there (more reliable than `xctrace`/`devicectl` output,
   which has changed format across Xcode versions).
6. **Register the device with your team, once, via Xcode's GUI Run.** The
   command-line `-allowProvisioningDeviceRegistration` flag (used by the
   preset below) doesn't reliably complete the device-registration
   round-trip with Apple's servers on its own. Do this once:
   - Open `build-ios/just-harmonizer.xcodeproj` (generate it first — see
     "Building" below).
   - Select the `just-harmonizer_AUv3` scheme with the iPad as the run
     destination, and press **Run (▶)** once.
   - After that succeeds, command-line builds will find the resulting
     provisioning profile without needing Xcode again.

## Building

```
export APPLE_TEAM_ID=<your team id>
export IOS_DEVICE_UDID=<your iPad's UDID>

cmake --preset ios-auv3
cmake --build --preset ios-auv3-debug
```

The `ios-auv3` configure preset uses the Xcode generator (required for iOS —
Ninja can't drive iOS code signing/bundling) and restricts the plugin to the
`Standalone` and `AUv3` formats. `Standalone` is required even though we only
care about AUv3: an AUv3 extension is just an `.appex` and can't be installed
on its own — it has to be embedded inside a container app, which JUCE builds
automatically when `Standalone` is also present, and that container is what
you actually install.

Build products land in `build-ios/Products` (pinned there via `SYMROOT` in
the build preset's `nativeToolOptions` — plain `-derivedDataPath` doesn't work
because CMake's Xcode generator drives `xcodebuild` with `-target`, not
`-scheme`, and `-derivedDataPath` only works with the latter).

## Installing on the iPad

```
find build-ios/Products -name "*.app" -path "*Debug-iphoneos*"
xcrun devicectl device install app --device $IOS_DEVICE_UDID "<path-to-.app>"
xcrun devicectl device process launch --device $IOS_DEVICE_UDID dev.kinga.just-harmonizer
```

### Trusting the developer certificate (first install only)

The very first launch attempt will be blocked by iOS with an "Untrusted
Developer" error. Fix once per device, per certificate:

1. On the iPad: **Settings → General → VPN & Device Management**.
2. Under **Developer App**, tap the entry for your account/team (e.g.
   "Kinga").
3. Tap **"Trust [Developer]"**, then confirm **Trust** in the popup.
4. Relaunch the app from the home screen.

## Known issue: the Standalone wrapper app crashes on launch

The installed `.app` (the JUCE `Standalone` container built solely to embed
the AUv3 extension) currently crashes immediately on iPad. This hasn't been
root-caused yet. It doesn't block the actual goal, though: installing that
app is enough for iOS to register the embedded AUv3 extension system-wide, so
**"Just Harmonizer" shows up and loads correctly inside AUv3 host apps**
(e.g. AUM, GarageBand) even though its own standalone wrapper doesn't open.

If/when someone investigates the crash: pull a crash log via `xcrun devicectl
device info crashinfo` or Xcode's Devices and Simulators → "Open Recent
Logs" for the device, and check for anything suspicious in JUCE's iOS
Standalone entry point.

## When the app "disappears"/stops working after ~7 days

Apps signed with a **free (non-paid) Apple Developer account** expire after 7
days — iOS deactivates them, and the icon may vanish from the home screen or
refuse to launch. This isn't a bug; it's an Apple platform restriction on
free-tier signing.

Fix: rebuild and reinstall — no re-signing step needed on your end, `cmake
--build` + `devicectl install` regenerates a fresh 7-day-valid signature:

```
cmake --build --preset ios-auv3-debug
xcrun devicectl device install app --device $IOS_DEVICE_UDID "<path-to-.app>"
```

If you outgrow the 7-day cycle (e.g. testing over a longer period), the only
real fix is enrolling in the paid Apple Developer Program ($99/year), which
issues profiles valid for a full year instead of 7 days.
