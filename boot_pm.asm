[org 0x7c00]

KERNEL_ADDR EQU 0x9FFF ;Kernel load location from disk
mov [boot_drive_adr], dl
mov bp, 0x9000 ;Move SP far away from code
mov sp, bp

mov dx, rm_msg
call print_string
call kernel_load
call switch_pm
jmp $

%include "./rm/print.asm"
%include "./rm/dl.asm"
%include "gdt.asm"
%include "print_pm.asm"
%include "switch_pm.asm"

[bits 16]

kernel_load:
    mov dx, kernel_msg
    call print_string
    mov bx, KERNEL_ADDR
    mov dh, 25
    mov dl, [boot_drive_adr]
    call load_disk
    ret

[bits 32]

start_pm:
    mov ebx, pm_msg
    call print_string_32
    ;mov ah, 0x01
    ;int 0x10
    call KERNEL_ADDR
    jmp $

rm_msg:
    db "Loaded 16-bit real mode",13,10,0

pm_msg:
    db "Loaded 32-bit protected mode",0

kernel_msg:
    db "Loading kernel",0

boot_drive_adr:
    db 0


times 510 - ($-$$) db 0
dw 0xaa55