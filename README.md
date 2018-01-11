# Gomoku-Strategy-Game-On-Nexys3
This project uses C++ to implement Gomoku and design the interface, uses VHDL language to migrate to FPGA and realize VGA display. 

software: XPS (Xilinx Platform Studio) 14.2 & SDK (Xilinx Software Development Kit)
Board: Nexys3
other hardware: usb keyboard, vga screen (640*480)

important files:
* system.xmp: project file
* \pcores\vga_ip_v1_00_a\hdl\verilog\user_logic.v: VHDL program
* \SDK\SDK_Export\lab_gobang_AI_2\src\lab_gobang_AI_2.c: main function of C++
* \SDK\SDK_Export\lab_gobang_AI_2\src\AI.c: the AI of Gomoku
* \SDK\SDK_Export\lab_gobang_AI_2\src\VGADraw.c: the functions used when designing game interface

Any problem about this project, just send me a message
