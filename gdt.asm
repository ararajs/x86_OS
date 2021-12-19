gdt_start:
;Each descriptor is 64 bits or 8 bytes
gdt_null:
    dd 0x0  ;Requires an invalid descriptor at first to initialize
    dd 0x0
gdt_code:   ;Code segment descriptor 
    dw 0xffff ;Limit [0:15] is 0xFFFFF, sets first 2 bytes of limit 
    dw 0x0 ;Base address [0:15]
    db 0x0 ; Base address [16:23]
    db 10011010b ;Segment Present [0] (1), DPL [1:2] (00 for ring 0), S [3], (1 for code), Type [4:8] (Code: 1, Conforming: 0, Readable: 1, Accessed: 0)
    db 11001111b ;Granularity [0] (1, allows us to extend segmentation by 16**3), D/B [1] (1 for 32 bit-segment), L [2] (0), AVL [3] (0, disabled for system use), Limit [4:8] (1111, sets [16:19] of limit)
    db 0x0 ;Base address [24:31]

gdt_data: ;Data segment descriptor, mostly similiar to code segment descriptor
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b ;Type bits [4:8] differ --> (Code: 0, Expand down: 0, Writable: 1, Accessed: 0)
    db 11001111b
    db 0x0

gdt_end: ;End label to get address location

gdt_descriptor:
    dw gdt_end - gdt_start - 1 ;Size of descriptor - 1 for gtd_end to be removed
    dd gdt_start ;Start address

CODE_SEG equ gdt_code - gdt_start ;Effective start address for code segment
DATA_SEG equ gdt_data - gdt_start ;Effective start address for data segment
