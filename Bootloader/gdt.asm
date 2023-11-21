[BITS    16]

loadgdt:
        cli
        lgdt [GDTR]

        ;Protection Enable bit on cr0
        mov eax, cr0
        or eax, 0x01
        mov cr0, eax

        ret

GDT:
        GDT.Entry:
                ;8 Null Bytes
                dd 0x00
                dd 0x00

        GDT.Code:
                ;Limit
                dw 0xFFFF
                
                ;Base
                dw 0x00
                db 0x00

                ;Type
                db 0x9A

                ;Flags
                db 0xCF

                ;Base
                db 0x00

        GDT.Data:
                ;Limit
                dw 0xFFFF
                
                ;Base
                dw 0x00
                db 0x00

                ;Type
                db 0x92

                ;Flags
                db 0xCF

                ;Base
                db 0x00

GDTR:
        dw GDTR - GDT - 1
        dd GDT
        

CODESEG equ GDT.Code - GDT
DATASEG equ GDT.Data - GDT