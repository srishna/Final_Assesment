#*****************************************************************************/
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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
ifeq ($(PLATFORM),MSP432) 
#Architectures Specific Flags
LINKER_FILE = -T /home/ecee/embedded_systems/ese-coursera-course1/assessments/m2/msp432p401r.lds
CC = arm-none-eabi-gcc
CPU = cortex-m4
ARCH = armv7e-m 
SPECS = nosys.specs

# Compiler Flags and Define
LD = arm-none-eabi-ld
TARGET = c1m2.out
LDFLAGS = -Wl,-Map=$(TARGET).map
CFLAGS=-Wall \
	-Werror \
	-g \
	-O0 \
	-std=c99
PLATFORM_FLAGS=-march=$(ARCH) \
		-mcpu=$(CPU) \
		--specs=$(SPECS) \
		-mthumb \
		-mfloat-abi=soft \
		-mfpu=fpv4-sp-d16 \
		-DMSP432 \
		-z muldefs
endif
ifeq ($(PLATFORM),HOST)
TARGET = c1m2.out
CC = gcc
CFLAGS=-Wall \
	-Werror \
	-g \
	-O0 \
	-std=c99 \
	-DHOST \
	-z muldefs
endif


CPPFLAGs = 

OBJS= $(SOURCES:.c=.o)
%.o:%.c
	$(CC) -c $< $(INCLUDES) $(CFLAGS) $(PLATFORM_FLAGS) -o $@

#.PHONY:	all
#build:	all
.PHONY:	build
build: $(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(OBJS) $(CFLAGS)	$(INCLUDES) $(PLATFORM_FLAGS) $(LINKER_FILE) $(SOURCES) $(LDFLAGS) -o $@ 

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).map

.PHONY:compile-all
compile-all:
	$(CC) -c $(SOURCES) $(INCLUDES) $(CFLAGS)

PREFILES = $(SOURCES:.c=.i)
%.i:%.c
	$(CC) $< -E -DHOST $(INCLUDES)

ASMFILES = $(SOURCSE:.c=.asm)
%.asm:%.c
	$(CC) $< -S -DHOST $(INCLUDES)
