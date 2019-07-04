# Undersanding memory allocation of the Code and Data sections of programs
In this programming assignment you will need to analyze some allocated memory. To do this, you will use a variety of the your knowledge gained in the module in addition to any of the GCC tools.

After completing this assignment, you will be able to:

* Use GCC Binary Utilities to investigate the memory usage of an executable
* Investigate the map file for the memory usage of an executable
* Determine where compiled code and data symbols are allocated, the lifetime of these symbols and the access restrictions

## Instructions:
You will use the GCC toolchain to help understand how your code and data are allocated in your memory space. To test your makefile you will need to download the assessments files for Course 1 from the github page.
```
cd ~
git clone https://github.com/afosdick/ese-coursera-course1.git
```
The folder contains 4 files:

* **main.c** - Main file you are to work with
* **misc.c** - File that declares some data and defines some functions
* **misc.h** - File that contains function declarations and macros
* **msp432p401r.lds** - Linker file for the msp432

Given the code and linker file provided from the zip file, you will need to specify where the listed symbols will be placed in our program.Once you have figured out your memory space, you can take the **Programming Assignment Quiz** where you will provide details about specific symbol elements including:

* **Location Top segment or Type** - Code, Data, Peripheral, Register, None
* **Location Sub-segment** - Stack, Heap, BSS, Data, const/rodata, None
* **Access Permissions** - Read (R), Write (W) Read-write (RW), None
* **Lifetime** - Function/Block, Program, Indefinite, None

## Suggestions:
There are multiple suggestions of tools you can use to help determine these answers besides just inspection.

1. You may generate a **.map** file using the linker flag -Wl,-Map=main.map
   * With this file you can look find certain assignments listed in the code.
2. You can use the GCC binary utility **nm** to investigate the code symbols
   * This will print code/data symbols with the memory properties
3. You can use the GCC toolchain and dump a file to assembly with the **-S** option.
   * This will provide some details on how a piece of data is allocated
4. You can add code to this to investigate the addresses that have been assigned to the variables and print those to the terminal
