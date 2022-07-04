kernel_src 	:= $(shell find kernel -name *.c)
kernel_obj 	:= $(patsubst kernel/%.c, build/kernel/%.o, $(kernel_src))

x86_asm_src := $(shell find arch/x86 -name *.asm)
x86_asm_obj := $(patsubst arch/x86/%.asm, build/x86/%.o, $(x86_asm_src))
x86_c_src 	:= $(shell find arch/x86 -name *.c)
x86_c_obj 	:= $(patsubst arch/x86/%.c, build/x86/%.o, $(x86_c_src))
x86_obj		:= $(x86_c_obj) $(x86_asm_obj)


$(kernel_obj): build/kernel/%.o : kernel/%.c
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -c -I include -ffreestanding $(patsubst build/kernel/%.o, kernel/%.c, $@) -o $@


$(x86_c_obj): build/x86/%.o : arch/x86/%.c
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -c -I include -ffreestanding $(patsubst build/x86/%.o, arch/x86/%.c, $@) -o $@

$(x86_asm_obj): build/x86/%.o : arch/x86/%.asm
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst build/x86/%.o, arch/x86/%.asm, $@) -o $@


.PHONY:	build-x86

build-x86: $(kernel_obj) $(x86_obj)
	mkdir -p dist/x86 && \
	x86_64-elf-ld -n -o dist/x86/kernel.bin -T targets/x86/linker.ld $(kernel_obj) $(x86_obj) && \
	cp dist/x86/kernel.bin targets/x86/iso/boot/kernel.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86/kernel.iso targets/x86/iso