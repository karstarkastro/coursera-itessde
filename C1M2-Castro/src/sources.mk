#******************************************************************************
# Copyright (C) 2020 by Pablo Castro
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. 
#
#*****************************************************************************

# Add your Source files to this variable
SOURCES =

# Add your include paths to this variable
INCLUDES =

ifeq ($(PLATFORM), HOST)
	SOURCES = \
		./main.c \
		./memory.c 		
	INCLUDES = \
		-I../include/common
else
	SOURCES = \
		./main.c \
		./memory.c \
		./system_msp432p401r.c \
		./startup_msp432p401r_gcc.c \
		./interrupts_msp432p401r_gcc.c 	
	INCLUDES = \
		-I../include/common \
		-I../include/msp432 \
		-I../include/CMSIS
endif	
