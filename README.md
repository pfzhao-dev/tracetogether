### This git repo contains an archived copy of the repo content for NUS CS4222 Team Project - TraceTogether, collaborated by Team 5, Academic Year 2020-21, Semester 2. Our Team consists of Yehezkiel, Wee Han and myself. Please refer to the [project-descriptions-Apr7.pdf](https://github.com/pfzhao-dev/tracetogether/blob/main/project-descriptions-Apr7.pdf) at the root directory to access the project requirements. Please refer [here](https://github.com/pfzhao-dev/tracetogether/tree/main/project-5) to access the source code as well as the project report.

## Compiling
make TARGET=srf06-cc26xx BOARD=sensortag/cc2650 trace_together.bin CPU_FAMILY=cc26xx

## Checking the usbmodem
ls /dev/tty* | grep usb

## Command to Run:
~/Program_Files/Contiki/contiki/tools/sky/serialdump-macos -b115200 /dev/tty.usbmodemL12491
