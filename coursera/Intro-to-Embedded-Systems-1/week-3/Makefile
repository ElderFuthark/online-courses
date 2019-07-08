#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile to generate an executable for both the MSP432 and my host system, x64.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      Any file be it, preprocessed, assembly, object, or executable can be built 
#      individually. This includes any dependencies. Several phony targets exist,
#      such as clean, build, compile-all, %.i, %.asm and %.o. 
#
# Platform Overrides:
#      MSP -- MSP432
#      HOST -- host machine
#
#------------------------------------------------------------------------------

# Platform Overrides
PLATFORM =				# Specified via command line
TARGET = c1m2
ifeq ($(PLATFORM), HOST)		# Host machine
     CC = /usr/bin/gcc
     # Architectures Specific Flags
     LD = /usr/bin/ld
     # Compiler Flags and Defines
     CFLAGS = -Wall -Werror -g -O0 -std=c99 -DHOST 
     LDFLAGS = -Wl,-Map=$(TARGET).map
else						# Target MSP432
     CC = /usr/bin/arm-none-eabi-gcc
	
     # Architectures Specific Flags
     LINKER_FILE = msp432p401r.lds  
     CPU = cortex-m4 
     ARCH = armv7e-m   
     FPU = fpv4-sp-d16    # Floating point unit
     FABI = hard          # Floating point application binary interface
     SPECS = nosys.specs  # specs file
	
     # Compiler Flags and Defines
     LD = /usr/bin/arm-none-eabi-ld
     CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) -march=$(ARCH) -mthumb \
		    -mfloat-abi=$(FABI) -mfpu=$(FPU) \
		    --specs=$(SPECS) -DMSP432
     LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	
endif

# Platform independent flags
CPPFLAGS = -E -MMD
SOURCES=main.c misc.c
OBJS = $(SOURCES:.c=.o)

%.o : %.c    # Generate any object file.
	$(CC) -c $< $(CFLAGS) -o $@

%.asm : %.c
	$(CC) -S $< $(CFLAGS) -o $@

%.i : %.c
	$(CC) $(CPPFLAGS) $< $(CFLAGS) -o $@
# Build rules
.PHONY: compile-all build clean
compile-all: $(SOURCES)
	$(CC) $(CFLAGS) -c $^
build: compile-all
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(TARGET).out
clean:
	rm -f *.o $(TARGET).out $(TARGET).map *.asm *.i *.d
