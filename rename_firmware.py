import os
import re
import shutil
from time import sleep

Import("env")

def rename_firmware(source, target, env):
    # Define the regex pattern to extract the firmware version
    version_pattern = re.compile(r'const char\* FIRMWARE_VERSION\s*=\s*"([^"]+)"')

    # Search for the firmware version in the source files
    firmware_version = None
    src_dir = env['PROJECT_SRC_DIR']
    for src_file_name in env.Glob(os.path.join(src_dir, "*.cpp")):
        src_file_path = str(src_file_name)
        with open(src_file_path, "r") as file:
            content = file.read()
            match = version_pattern.search(content)
            if match:
                firmware_version = match.group(1)
                print(f"Extracted firmware version: {firmware_version} from {src_file_path}")
                break

    if not firmware_version:
        raise ValueError("Could not extract firmware version from source files.")

    # Get the source and destination paths using PlatformIO variables
    build_dir = env.subst("$BUILD_DIR")
    firmware_src = os.path.join(build_dir, "firmware.bin")
    firmware_dst = os.path.join(build_dir, f"firmware_v{firmware_version}.bin")

    # Ensure the firmware file exists and wait if necessary
    retries = 5
    while not os.path.isfile(firmware_src) and retries > 0:
        print(f"Firmware file not found: {firmware_src}. Retrying...")
        sleep(1)  # Wait for 1 second before retrying
        retries -= 1

    # Handle existing firmware files
    if os.path.isfile(firmware_src):
        if os.path.isfile(firmware_dst):
            print(f"Existing file found: {firmware_dst}. Deleting the old file.")
            os.remove(firmware_dst)
        shutil.copy(firmware_src, firmware_dst)
        print(f"Firmware file renamed to: firmware_v{firmware_version}.bin")

        # Delete the original firmware.bin file
        os.remove(firmware_src)
        print(f"Original firmware.bin file deleted.")

        # Create a symlink or copy to ensure upload command works
        shutil.copy(firmware_dst, firmware_src)
        print(f"Symlink or copy created for firmware upload.")
    else:
        raise FileNotFoundError(f"Firmware file not found after retries: {firmware_src}")

# Add the post-action to run after the build process is complete
env.AddPostAction("buildprog", rename_firmware)

# Ensure the script always runs
env.AddPreAction("upload", rename_firmware)
