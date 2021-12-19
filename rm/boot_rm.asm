;Boot sector code
;0x7c00 is relative MBR (Master Boot Record) location, hence assembly codes start from there.
;AH = 0x00  and int 0x16 for write char
;AH = 0x0E and int 0x10 for teletype dis
;;Little endianess :- LSB to MSB in memory (LSB is accessed before MSB)
;;Boot sector loads exactly, hence if DH val is higher than total number of sectors available, there might be a disc error.

[org 0x7c00] ;To let code do relative indexing for data with respective to MBR
mov [boot_drive_adr], dl
mov bp, 0x8000 ;Move stack pointer far away where it cannot be disrupted by boot sector
mov sp, bp
mov bx, 0x9000 ;Move load location of the next x-sectors, and ensure that it does not collide with the stack pointer
mov dh, 0x4 ;4 sectors to be read, if higher than the actual amount of sectors leads to a disk load error
mov dl, [boot_drive_adr]
call load_disk

mov dx, [0x9000]
call print_hex ;Expect 0xdada -> Pass

mov dx, [0x9000 + 1024]
call print_hex ;Expect 0x6969 -> Pass

mov dx, [0x7e02]
call print_hex 

jmp $

%include "print.asm"
%include "dl.asm"

boot_drive_adr:
    db 0

times 510 - ($-$$) db 0
dw 0xaa55

;Additional sector sim --> 512 bytes x 4 sectors = 2 kB 
times 256 dw 0xdada
times 256 dw 0xface
times 256 dw 0x1234
times 256 dw 0x6969
