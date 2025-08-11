CC := i686-elf-gcc
ASM := nasm

ASMFLAGS := -f elf32
CFLAGS := -ffreestanding -m32 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -g -O0
WARNFLAGS := -Wall -Werror

ROOT := $(CURDIR)
COMPILED := $(ROOT)/files/source/compiled
DEPS := $(ROOT)/files/source/deps
SOURCES := $(ROOT)/files
HEADER := -I$(HOME)/opt/cross/lib/gcc/i686-elf/15.2.0/include -I$(ROOT)/files/sources/libraries
INCLUDEASM := $(ROOT)/files/sources


SRCFILES := $(shell find $(SOURCES) -name '*.c')
ASMFILES := $(shell find $(SOURCES) -name "*.s")

DP := $(ROOT)/src/deps
OBJFILESC := $(patsubst %.c, %.o, $(SRCFILES))
OBJFILESA := $(patsubst %.s, %.o, $(ASMFILES))


DEPC := $(patsubst %.c,%.d,$(SRCFILES))

-include $(DEPC) 

OBJLIST := $(OBJFILESC) $(OBJFILESA)


all: clean $(OBJFILESC) $(OBJFILESA) link move iso run

.PHONY: clean move link isomove run test



clean:
	@echo "Cleaning..."
	-@$(RM) $(wildcard $(COMPILED)/*.o)
	-@$(RM) $(wildcard $(DP)/*.d)


%.o: %.c 
	@$(CC) $(HEADER) $(CFLAGS) $(WARNFLAGS) -MMD -MP -c $< -o $@

%.o: %.s

	@$(ASM) -i $(INCLUDEASM) $(ASMFLAGS) $< -o $@


link: $(OBJLIST)
	@echo "Linking..."
	@i686-elf-ld -T files/source/linker.ld -o kernel.bin $(OBJLIST)

move:
	@echo "Moving to compiled"

	-@for file in $(OBJLIST); do \
		mv $$file $(COMPILED); \
	done

	-@for file in $(DEPC); do \
		mv $$file $(DEPS); \
	done


iso:
	@echo "Moving ISO"
	@mv kernel.bin $(HOME)/Documents/Yauc/files/isofiles/boot
	@echo "Creating ISO..."

	@grub-mkrescue -o yauc.iso $(HOME)/Documents/Yauc/files/isofiles


run: 
	@echo "Running..."
	@qemu-system-i386 -cdrom yauc.iso