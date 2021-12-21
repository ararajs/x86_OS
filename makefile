
C_SOURCES = $(wildcard *.c)
#HEADERS = $(wildcard *.h )
#OBJ = $(wildcard *.o)

all: os-image
	qemu-system-x86_64 $^

os-image: boot_pm.bin kernel.bin
	copy /b boot_pm.bin+kernel.bin os-image

kernel.bin: kernel_entry.o kernel.o interrupt.o  
	ld -Ttext 0x9FFF $^ -o kernel.pe
	objcopy -O binary kernel.pe kernel.bin


%.o: %.c
	gcc -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf32 -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	del /S *.pe *.o *.bin os-image



