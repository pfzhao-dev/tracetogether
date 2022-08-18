# Compiling
make TARGET=srf06-cc26xx BOARD=sensortag/cc2650 trace_together.bin CPU_FAMILY=cc26xx

# Checking the usbmodem
ls /dev/tty* | grep usb

# Command to Run:
~/Program_Files/Contiki/contiki/tools/sky/serialdump-macos -b115200 /dev/tty.usbmodemL12491
