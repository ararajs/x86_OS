[bits 16]

switch_pm:
    cli ;Clear real mode interrupts
    lgdt [gdt_descriptor]
    mov eax, cr0 ;Set fist bit of cr0 to indicate change to 32-bit mode
    or eax, 0x1
    mov cr0, eax
    jmp CODE_SEG:initialize_pm

[bits 32]

initialize_pm:
    mov ax, DATA_SEG ;Modify the new data segment registers to the value given in the GDT
    mov ds, ax
    mov fs, ax
    mov es, ax
    mov ss, ax
    mov gs, ax 

    mov ebp, 0x90000
    mov esp, ebp
    call start_pm

