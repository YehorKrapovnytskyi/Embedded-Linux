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
# This makefile maintains building for two Platforms: MSP432 and HOST
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <File>.o - build an object file <File>.o
#			 <File>.asm - build an assemply file <File>.asm
#			 <File>.i - build a preproccesed file <File>.i
#			 <File>.d - build a dependency file <File>.d
#			 compile-all - compile and assemble all source files without linking
#			 build - compile all files and generate output file
#			 clean - remove all intermediate compilation files
#
# Platform Overrides:
#      HOST - default platform
#      MSP432 - Target cross-compiled platform			
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

GEN_FLAGS = -Wall    \
						-Werror  \
						-g			 \
						-O0      \
						-std=c99

TARGET = c1m2

ifeq ($(PLATFORM),MSP432)
      INCLUDES = -I ../include/common \
					 			 -I ../include/CMSIS  \
					       -I ../include/msp432

			# Architectures Specific Flags
      LINKER_FILE = -T msp432p401r.lds
      CPU = cortex-m4
      ARCH = thumb
      SPECS = nosys.specs
      EXTRA = -march=armv7e-m	   \
			        -mfloat-abi=hard   \
							-mfpu=fpv4-sp-d16




			# Compiler Flags and Defines
      CC = arm-none-eabi-gcc
      LD = arm-none-eabi-ld
      LDFLAGS = -Wl,-Map=$(TARGET).map -T -L ../ $(LINKER_FILE)
      CFLAGS = $(GEN_FLAGS) $(EXTRA) -mcpu=$(CPU) --specs=$(SPECS) -m$(ARCH)
      CPPFLAGS = -DMSP432 $(INCLUDES)
      SOURSES = main.c   						 				 \
								memory.c 						 				 \
								system_msp432p401r.c 				 \
								startup_msp432p401r_gcc.c 	 \
								interrupts_msp432p401r_gcc.c

      SIZE = arm-none-eabi-size

else
      CC = gcc
      CFLAGS = $(GEN_FLAGS)
      CPPFLAGS = -DHOST $(INCLUDES)
      LDFLAGS = -Wl,-Map=$(TARGET).map
      SIZE = size
endif

OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.asm)
PREP = $(SOURCES:.c=.i)
DEPS = $(SOURCES:.c=.d)



%.o: %.c
		$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm: %.c
		$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.i: %.c
		$(CC) -E $< $(CPPFLAGS) -o $@

%.d: %.c
		$(CC) -E -M $< $(CPPFLAGS) -o $@

.PHONY:compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
		$(CC) -o c1m2.out $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
		$(SIZE) $@

.PHONY: clean
clean:
		rm -rf $(OBJS) $(DEPS) $(ASMS) $(PREP) $(TARGET).out $(TARGET).map
