# dds-pinc
A simple Vitis HLS core to provide phase increments to the Xilinx DDS core.

This core creates an AXI4-Lite register where the user can write a phase increment. The phase increment is converted to an AXI4-Stream and streamed to the Xilinx DDS core. The streamed value is updated when the user writes a new value to the register. The DDS core this IP was designed to work with is programmed to run with a 128 MHz clock in rasterized mode with a modulus of 16384 so that it can output frequencies between 0 and 128 MHz with 7.8125 KHz of precision to match the DAC LUT. The output frequency is given by $\mathrm{pinc}*(128 \mathrm{MHz}/16384)=\mathrm{pinc}*7.8125 \mathrm{kHz}$.

Expected testbench output:
```
HLS AXI-Lite to AXI-Stream Phase Increment Player
first phase increment: 1023, second phase increment: 4
Beginning tests:

TEST1: AXI-Lite input: 1023, AXI-Stream output: 1023
success!
TEST 2: AXI-Lite input: 4, AXI-Stream output: 4
success!
TEST 3: AXI-Lite input: 4, AXI-Stream output: 4
success!
ALL TESTS PASSED! :)
```
