[org 0x7c00]

mov bp, 0x9000 ;Move SP far away from code
mov sp, bp

mov dx, rm_msg
call print_string
call switch_pm
jmp $

%include "./rm/print.asm"
%include "gdt.asm"
%include "print_pm.asm"
%include "switch_pm.asm"

[bits 32]

start_pm:
    mov ebx, pm_msg
    call print_string_32
    jmp $

rm_msg:
    db "Loaded 16-bit real mode",13,10,0

pm_msg:
    db "Loaded 32-bit protected mode", 0

times 510 - ($-$$) db 0
dw 0xaa55