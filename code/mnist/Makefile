.PHONY: all clean 


SRCDIR=src
BUILDDIR=build
LOCALBUILDDIR=local_build



SOURCES=$(notdir $(wildcard $(SRCDIR)/*.c))
HEADERS=$(notdir $(wildcard $(SRCDIR)/*.h))
SRCBASES=$(basename $(SOURCES))

OBJS := $(SRCBASES:%=$(BUILDDIR)/%.o)
OBJS += $(BUILDDIR)/crt0.o
LOCALOBJS := $(SRCBASES:%=$(LOCALBUILDDIR)/%.o)

GOALS = $(BUILDDIR)/mnist_suite.hex $(BUILDDIR)/mnist_suite.dump

# TESTS=$(basename $(SOURCES))
# ELF=$(addprefix build/,$(TESTS))
# ELF32=$(addsuffix 32,$(ELF))
# HEX32=$(addsuffix .hex,$(ELF32))
ELF2HEX=../elf2hex

RISCVCCPREFIX =riscv64-unknown-elf-
RISCVCC32=$(RISCVCCPREFIX)gcc
RISCVCCOBJDUMP =$(RISCVCCPREFIX)objdump

RISCV_CFLAGS=-mcmodel=medany -nostdlib -nostartfiles -march=rv32i -mabi=ilp32 -mstrict-align -O2 
RISCV_LDFLAGS=-march=rv32i -nostdlib -nostartfiles -Wl,-Tsrc/riscv-link.ld

all: $(GOALS) local

$(ELF2HEX)/elf2hex: 
	cd $(ELF2HEX) && $(MAKE) clean && $(MAKE)

#################################
## BUILDING RISCV MNIST DETECTION
#################################

# dump file
$(BUILDDIR)/mnist_suite.dump: $(BUILDDIR)/mnist_suite
	$(RISCVCCOBJDUMP) -s -d $< > $@

#hex file, for main mem intialization
$(BUILDDIR)/mnist_suite.hex: $(BUILDDIR)/mnist_suite $(ELF2HEX)/elf2hex
	$(ELF2HEX)/elf2hex $< 0 16G $@

#the main bad boy, linking the objects together
$(BUILDDIR)/mnist_suite: $(OBJS) 
	$(RISCVCC32)  $(OBJS) -o $@ $(RISCV_LDFLAGS)

# getting the object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(BUILDDIR)
	$(RISCVCC32)  $(RISCV_CFLAGS) -c $< -o $@ 

# that one assembly file 
$(BUILDDIR)/crt0.o: src/crt0.S
	mkdir -p $(BUILDDIR)
	$(RISCVCC32) -c src/crt0.S -o $(BUILDDIR)/crt0.o $(RISCV_CFLAGS)

###################
# LOCAL COMPILATION
###################
local: $(LOCALOBJS)
	cc $(LOCALOBJS) -o $@ $(LDFLAGS) 

$(LOCALBUILDDIR)/%.o: $(SRCDIR)/%.c 
	mkdir -p $(LOCALBUILDDIR)
	cc -c $< -o $@ -D LOCAL


##################
clean:
	rm -rf build
	rm -rf local_build 
	rm -f ../elf2hex/elf2hex
