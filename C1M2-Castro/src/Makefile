#******************************************************************************
# Copyright (C) 2020 by Pablo Castro
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software.
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This makefile allows the user to choose between obtaining the preprocessed, 
# assembly, object or final output executable files of the c-program implementation
# files.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#			FILE.i: where FILE can be any of the c-program implementation files. Generates
#			the preprocessed output of all c-program implementation files.
#			FILE.asm: where FILE can be any of the c-program implementation files. Generates 
#			assembly output of c-program implementation files and the final output executable.
#			FILE.o: where FILE can be any of the c source files. Generates the object file for 
#			all c-source files.
#			compile-all: compiles all object files (but without linking).
#			build: compiles all object files and links them into a final executable called c1m2.out
#
# Platform Overrides:
#		Used to determine the compiler that will be used and other specific flags. 
#		It can be assigned one of these two values:
#			MSP432: for the embedded system of the same name. The arm-none-eabi-gcc compiler will be used.
#			HOST: for the host environment. The gcc compiler will be used.
#------------------------------------------------------------------------------
include sources.mk

#name of the output file
OUTPUT = c1m2.out

# Platform Overrides
PLATFORM = 

# Architectures Specific Flags
LINKER_FILE = 
CPU = 
ARCH = 
SPECS = 

# Compiler Flags and Defines
CC = 
LD = 
LDFLAGS = -O0 -Xlinker -Map=$(OUTPUT:.out=.map)
CFLAGS = -Wall -Werror -g -std=c99
CPPFLAGs = -MD
SFLAG =
ODUMP =

ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	override PLATFORM = -DMSP432
	override LDFLAGS += -T 
	LINKER_FILE = ../msp432p401r.lds
	CPU = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
	ARCH = -march=armv7e-m
	SPECS = -specs=nosys.specs
	SFLAG = arm-none-eabi-size -At $(OUTPUT)
	ODUMP = arm-none-eabi-objdump 
else
	CC = gcc
	override PLATFORM = -DHOST
	SFLAG = size -At $(OUTPUT)
	ODUMP = objdump 
endif

#DEFINITION OF TARGETS


#generation of preprocessing files
%.i:%.c
	$(CC) $(PLATFORM) $(CFLAGS) $(INCLUDES) $(CPU) $(ARCH) $(SPECS) -E -o $@ $^  
#generation of assembly from c files
%.asm:%.c
	$(CC) $(PLATFORM) $(CFLAGS) $(INCLUDES) $(CPU) $(ARCH) $(SPECS) -S -o $@ $^  

#generation of assembly from final executable files
%.asm:%.out
	$(ODUMP) -S -d $^ > $@ 

#generation of object files
%.o:%.c
	$(CC) $(PLATFORM) $(CFLAGS) $(INCLUDES) $(CPU) $(ARCH) $(SPECS) -c $^

#compilation of all object files
.PHONY: compile-all
compile-all:$(SOURCES)
	$(CC) $(PLATFORM) $(CFLAGS) $(INCLUDES) $(CPU) $(ARCH) $(SPECS) -c $^ 

.PHONY: build
OBJS:=$(SOURCES:.c=.o)
build:compile-all 
	$(CC) $(PLATFORM) $(CFLAGS) $(INCLUDES) $(CPPFLAGs) $(CPU) $(ARCH) $(SPECS) $(LDFLAGS) $(LINKER_FILE) \
	-o $(OUTPUT) $(OBJS)
	$(SFLAG)

.PHONY: clean
clean:
	$(RM) *.i *.asm *.o *.map *.out *.d
