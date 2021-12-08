;Boot sector code
;0x7c00 is relative MBR (Master Boot Record) location, hence assembly codes start from there.
;AH = 0x00  and int 0x16 for write char
;AH = 0x0E and int 0x10 for teletype dis

[org 0x7c00] ;To let code do relative indexing for data with respective to MBR




mov dx, string
call print_string
mov dx, 0x1234
call print_hex
jmp $


%include "print.asm"

string: 
    db "Hello!",13,10,0



times 510 - ($-$$) db 0
dw 0xaa55