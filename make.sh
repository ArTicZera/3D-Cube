nasm -fbin Bootloader/boot.asm -o Bin/boot.bin
nasm -fbin Bootloader/stg2.asm -o Bin/stg2.bin
nasm -felf Kernel/entry.asm    -o Bin/entry.o

export PATH="$PATH:/usr/local/i386elfgcc/bin"

FLAGS="-ffreestanding -m32 -g"

ENTRY="Bin/entry.o"
OBJS="Bin/kernel.o"

i386-elf-gcc $FLAGS -c Kernel/kernel.cpp -o Bin/kernel.o

i386-elf-ld -o Bin/fullkrnl.bin -Ttext 0x1000 $ENTRY $OBJS --oformat binary

cat Bin/boot.bin Bin/stg2.bin > Bin/fullboot.bin
cat Bin/fullboot.bin Bin/fullkrnl.bin > Cube.img