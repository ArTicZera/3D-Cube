[BITS    16]
[ORG 0x7C00]

%define STAGE2 0x7E00
%define VIDMOD 0x0013

jmp setup

setup:
        xor ax, ax
        mov es, ax
        mov ds, ax

        mov sp, 0x7C00
        mov ss, ax

        call stg2sectors
        call setvideomode

        jmp 0x0000:STAGE2

stg2sectors:
        mov ah, 0x02
        mov al, 0x02
        mov ch, 0x00
        mov cl, 0x02
        mov dh, 0x00

        xor bx, bx
        mov es, bx

        mov bx, STAGE2

        int 0x13

        ret

setvideomode:
        mov ax, VIDMOD
        int 0x10

        ret

times 510 - ($ - $$) db 0x00
dw 0xAA55