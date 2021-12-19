input:
    pusha
    mov ah, 0x00
    int 0x16
    mov ah, 0x0E
    int 0x10
    popa
    ret

print_string:
    pusha
    mov di, dx
    mov si, dx
    xor cx, cx
    sub al, al
    not cx
    cld
    repne scasb
    not cx
    dec cx
    mov dx, cx
    mov ah, 0x0E
    .print_loop:
        mov al, [si]
        int 0x10
        cmp dx, 0x1
        je .exit
        dec dx
        add si, 1
        jmp .print_loop        
    .exit:
        popa
        ret
        
print_hex:
    pusha
    mov ah, 0x0E
    mov al, 0x30
    int 0x10
    mov al, 0x78
    int 0x10
    mov bx, hex_table
    .hex_fn:
        push dx
        shr dx, 12
        mov al, dl
        xlat
        int 0x10
        pop dx
    .hex_sn:
        push dx
        shr dx, 8
        and dx, 0x0F
        mov al, dl
        xlat
        int 0x10
        pop dx
    .hex_tn:
        push dx
        shr dx, 4
        and dx, 0x00F
        mov al, dl
        xlat
        int 0x10
        pop dx
    .hex_fon:
        push dx
        and dx, 0x000F
        mov al,dl
        xlat
        int 0x10
        pop dx
    mov al, 0
    int 0x10
    popa
    ret

hex_table:
    db "0123456789abcdef",0