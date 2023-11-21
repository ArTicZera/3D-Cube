[BITS    16]
[ORG 0x7E00]

%define KERNEL 0x1000
%define SECTRS 0x0008

jmp main

main:
        call krnlsectors
        call loadgdt

        jmp CODESEG:pmode

krnlsectors:
        ;4096 bytes
        mov ah, 0x02
        mov al, SECTRS
        mov ch, 0x00
        mov cl, 0x03
        mov dh, 0x00

        xor bx, bx
        mov es, bx

        mov bx, KERNEL

        int 0x13

        ret

DRV: db 0x00

%include "Bootloader/gdt.asm"
%include "Bootloader/pmode.asm"

times 512 - ($ - $$) db 0x00
