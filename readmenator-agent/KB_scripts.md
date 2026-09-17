# Subsystem: scripts

## esp32-qemu-test/scripts/gen_exploit_image.py
- Layer: testing
- Doc: gen_exploit_image.py — Generate and inject the ESP32 QEMU PoC storage image.  The image is intentionally hybrid so one r
- Language: py
- Symbols:
  - `lfn_checksum` (function, line 67) `def lfn_checksum(short_name_11)`
  - `build_lfn_entries` (function, line 76) `def build_lfn_entries(long_name, short_name_11)`
  - `resolve_symbol_address` (function, line 115) `def resolve_symbol_address(elf_path, symbol_name)`
  - `build_xtensa_uart_shellcode` (function, line 149) `def build_xtensa_uart_shellcode()`
  - `build_payload_sector` (function, line 271) `def build_payload_sector(shellcode, callback_target_addr)`
  - `generate_bug1_espidf_image` (function, line 282) `def generate_bug1_espidf_image(shellcode, callback_target_addr)`
  - `inject_into_flash` (function, line 389) `def inject_into_flash(flash_path, output_path, shellcode, callback_target_addr)`
  - `main` (function, line 456) `def main()`

## esp32-qemu-test/scripts/run_test.sh
- Layer: testing
- Doc: =========================================================================== run_test.sh — Build, inject, and run the ESP
- Language: sh
