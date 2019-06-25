# Automating the build process with makefiles

In this programming assignment you will create a build system using the GNU tools, GCC and GNU Make. This assignment will require you to compile multiple files, link them together and create a final output executable. Some files will be provided for you, but you will need to support two platforms; the host environment and the target embedded system MSP432. The host system will allow you to simulate software on a host platform. The target system will be used in upcoming assignments as we begin to create our microcontroller applications.

You will write a makefile that can compile multiple source files and support two platform targets.
* msp432p401r.lds - The linker file you are to use for linking
**‘src’ folder** : contains five source files (*.c)

Makefile - The makefile you are to edit for the assignment sources.mk - The source file you are to edit for the assignment
* main.c - Main file you are to work with
* memory.c - File that interacts with memory through an IO abstraction interface
* interrupts_msp432p401r_gcc.c - MSP432 specific C-file for interrupts
* startup_msp432p401r_gcc.c - MSP432 specific C-file for startup
* system_msp432p401r.c - MSP432 specific C-file for for system information
**‘include’ folder** : contains the three directories of supporting header files

* **common** - Contains common headers for both platform targets
* **msp432** - Contains MSP432 platform headers
* **CMSIS** - Contains ARM architecture specific headers
Inside the **common** folder, you have been provided a memory.h and a platform.h file. The platform.h file gives you an interface to printf using the macro PRINTF as a mechanism to reduce the dependencies on the stdio.h library.

## Platforms and Flag Support Guidelines

You need to support two target platforms and their own specific compilers. These two platforms are the HOST and the MSP432. The host embedded system will use the native compiler, **gcc**. The target embedded system will use the cross compiler, **arm-none-eabi-gcc**. The **PLATFORM** keyword provided in the Makefile should be used to conditionally assign the appropriate compiler flags, linker flags, and architecture flags. The target platform must be provided at the command line with the make command to set the platform you are compiling for.

_Example:_
```bash
make build PLATFORM=MSP432
make build PLATFORM=HOSTa
```
Upon completion of a build, you should provide a build report of code **size** using the gcc size tool. Note, you will need to select the right GCC Toolchain Size application. The output executable that gets built needs to be called **c1m2.out**. This needs to be executed using dot-slash notation (./c1m2.out)

The Makefile and sources.mk files have already been populated with a few makefile variables that you will need to define at a minimum. Those are listed below:

* **CC** - Compiler that will perform the build (Native or Cross)
* **CFLAGS** - C-programming flags for gcc
* **CPPFLAGS** - C-Preprocessor Flags
* **LDFLAGS** - Linker Flags
* **PLATFORM** - The target platform you are compiling for (Platform Specific)
* **SOURCES** - The list of sources files that will need to be compiled (Platform specific)
* **INCLUDES** - The list of include directories ( Hint: Use the -I flag )

You will need to generate a handful of files for each complete build. These are:

* **c1m2.map** - Map file for the full build ( Use the -Map=<FILE> option )
* ***.d** - Dependency Files for each source file (main.dep, memory.dep, etc) ( Use the -M* options [MP, MF, MD, MM, etc])
* ***.o** - Individual object files (main.o, memory.o, etc)
* **c1m2.out** - Output Executable file

For building will need to support a variety of flags. These will include general, platform and architecture specific flags. Those are listed below

General Flags (Both Platforms)

* -Wall
* -Werror
* -g
* -O0
* -std=c99
Platform Specific Flags (MSP432/HOST)

* **Linker File (MSP432)**: -T msp432p401r.lds
* **Platform Target (Both)**: -DMSP432 or -DHOST
Architecture Specific Flags (ARM only)

* -mcpu=cortex-m4
* -mthumb
* -march=armv7e-m
* -mfloat-abi=hard
* -mfpu=fpv4-sp-d16
* --specs=nosys.specs
You may **NOT** use wildcard searches for finding source files. You must directly define the files you wish to compile and the directories you wish to include based on the platform. To do this, you will need to define the sources and include list differently based on the target platform. Use a conditional check to switch between these. An example below provides a hint on how to do this:
```makefile
ifeq ($(PLATFORM),HOST)
     CC = <Add the appropriate compiler>
     # etc
else
     CC = <Add the appropriate compiler>
     # etc
endif
```

## Build target guidelines
Build Target Guidelines

You need to support a number of build rules and target files. Any rule with a prerequisite list must have only dependent files and dependent targets listed. For any prerequisite that is in another build target prerequisite list, that target dependency needs to execute those rules before running the initially provided target. Finally, you do NOT need to go from source file to preprocessor file to assembly file to object file to relocatable file to executable file for this build. You can have build rules that directly compile a file.

Below are the targets which need to be supported in the makefile:

**%.i**

* Generate the preprocessed output of all c-program implementation files (use the –E flag).
* You can do this by providing a single target name.

**%.asm**

* Generate assembly output of c-program implementation files and the final output executable (Use the –S flag and the objdump utility).
* You can do this by providing a single target name.

**%.o**

* Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.

**compile-all**

* Compile all object files, but DO NOT link.
* Needs to have .PHONY protection.

**Build**

* Compile all object files and link into a final executable.
* Needs to have .PHONY protection.

**Clean**

* This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
* Needs to have .PHONY protection.
* This includes but is not limited to .map, .out, .o, .asm, .i etc.

**Disclaimer: This README file corresponds nearly word-for-word to the assignment description provided by the Introduction to Embedded Systemd 1 course on Coursera. It's replication here is purly for reference when looking back at this assignment in the future. All rights are reserved by Coursera and any individuals or entities involved in the creation of this text**
