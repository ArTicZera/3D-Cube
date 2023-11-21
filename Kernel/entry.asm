section .text
        global _start

_start:
        [BITS     32]
        [EXTERN main]

        call main

        jmp $