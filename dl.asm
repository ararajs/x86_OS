;AH = 0x02, BIOS read sector mode
;int 0x13 to perform read action


load_disk:
    push dx
    mov ah, 0x02
    mov al, dh
    mov ch, 0x00 ; Cylinder 0
    mov dh, 0x00 ; Head 0
    mov cl, 0x02 ; Sector 2 -> Read from sector 2 onwards, after the base load
    int 0x13
    jc disk_load_error
    pop dx
    cmp dh, al
    jne disk_load_error
    ret

disk_load_error:
    mov dx, disk_error_msg
    call print_string
    jmp $

disk_error_msg:
    db "Disk load error!",0

