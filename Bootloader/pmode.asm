[BITS    32]

pmode:
        mov ax, DATASEG

        mov ds, ax
        mov es, ax
        mov fs, ax
        mov gs, ax
        mov ss, ax

        mov ebp, 0x10000
        mov esp, ebp

        ;Enable A20 Gate
        in al, 0x92
	or al, 0x02
	out 0x92, al

        jmp KERNEL