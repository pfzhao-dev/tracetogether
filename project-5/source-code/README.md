# Running on CC2650

Compile and execute the trace together code by doing the following:
- Place the given folder named "source-code" under contiki/examples/.
- Compile the trace_together program using command "make TARGET=srf06-cc26xx BOARD=sensortag/cc2650 trace_together.bin CPU_FAMILY=cc26xx" in the directory "contiki/examples/source-code".
- Use uniflash program to burn the binary file to the SensorTag
- Observe the output of the program through the USB serial port.

# Running on Cooja

Compile and execute the trace together code by doing the following:
- Place the given folder named "source-code" under contiki/examples/.
- Compile the trace_together program using command "make TARGET=sky trace_together.upload" in the directory "contiki/examples/source-code".
- Run Cooja (using the command “ant run” in the contiki/tools/cooja directory)
- Open the simulator file: “File->Open_simulation” and choose the “contiki/examples/source-code/cooja_trace_together.csc” file.
