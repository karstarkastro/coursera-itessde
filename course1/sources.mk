#******************************************************************************
# Copyright (C) 2020 by Pablo Castro
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. 
#
#*****************************************************************************

ifeq ($(PLATFORM), HOST)
	SOURCES = \
		src/main.c \
		src/memory.c \
		src/stats.c \
		src/data.c \
		src/course1.c
	INCLUDES = \
		-Iinclude/common
else
	SOURCES = \
		src/main.c \
		src/memory.c \
		src/data.c \
		src/course1.c \
		src/stats.c \
		src/system_msp432p401r.c \
		src/startup_msp432p401r_gcc.c \
		src/interrupts_msp432p401r_gcc.c
	INCLUDES = \
		-Iinclude/common \
		-Iinclude/msp432 \
		-Iinclude/CMSIS
endif	