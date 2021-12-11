[bits 32]

VGA_MEM equ 0xb8000
COLOR equ 0x0f
;Formula for video memory for VGA is 0xb8000 + 2 * (row * 80 + col)
print_string_32:
    pusha
    mov edx, VGA_MEM
    .print_loop:
        mov al, [ebx]
        mov ah, COLOR
        cmp al,0
        je .done
        mov [edx + 2*(9*80+0)], ax
        add ebx,1
        add edx,2
        jmp .print_loop
    .done:
        popa
        ret