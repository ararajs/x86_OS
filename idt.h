extern void _idt_flush(uint32_t);


struct idt_entry_struct
{
   uint16_t base_lo;             
   uint16_t sel;                 
   uint8_t  always0;             
   uint8_t  flags;               
   uint16_t base_hi;             
} __attribute__((packed));
typedef struct idt_entry_struct idt_entry_t;


struct idt_ptr_struct
{
   uint16_t limit;
   uint32_t base;                
} __attribute__((packed));
typedef struct idt_ptr_struct idt_ptr_t;

idt_entry_t idt_entries[256];
idt_ptr_t   idt_ptr;

    extern void _isr0 ();
    extern void _isr1 ();
    extern void _isr2 ();
    extern void _isr3 ();
    extern void _isr4 ();
    extern void _isr5 ();
    extern void _isr6 ();
    extern void _isr7 ();
    extern void _isr8 ();
    extern void _isr9 ();
    extern void _isr10 ();
    extern void _isr11 ();
    extern void _isr12 ();
    extern void _isr13 ();
    extern void _isr14 ();
    extern void _isr15 ();
    extern void _isr16 ();
    extern void _isr17 ();
    extern void _isr18 ();
    extern void _isr19 ();
    extern void _isr20 ();
    extern void _isr21 ();
    extern void _isr22 ();
    extern void _isr23 ();
    extern void _isr24 ();
    extern void _isr25 ();
    extern void _isr26 ();
    extern void _isr27 ();
    extern void _isr28 ();
    extern void _isr29 ();
    extern void _isr30 ();
    extern void _isr31 ();
    extern void _irq0 ();
    extern void _irq1 ();
    extern void _irq2 ();
    extern void _irq3 ();
    extern void _irq4 ();
    extern void _irq5 ();
    extern void _irq6 ();
    extern void _irq7 ();
    extern void _irq8 ();
    extern void _irq9 ();
    extern void _irq10 ();
    extern void _irq11 ();
    extern void _irq12 ();
    extern void _irq13 ();
    extern void _irq14 ();
    extern void _irq15 ();



static void init_idt();
static void idt_set_gate(uint8_t,uint32_t,uint16_t,uint8_t);

static void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags)
{
   idt_entries[num].base_lo = base & 0xFFFF;
   idt_entries[num].base_hi = (base >> 16) & 0xFFFF;
   idt_entries[num].sel     = sel;
   idt_entries[num].always0 = 0;
   idt_entries[num].flags   = flags;
} 
static void init_idt()
{
    idt_ptr.limit = sizeof(idt_entry_t) * 256-1;
    idt_ptr.base  = (uint32_t)&idt_entries;
    memset(&idt_entries, 0, sizeof(idt_entry_t)*256);
    unsigned char a1,a2;
    a1 = port_byte_in(0x21);
    a2 = port_byte_in(0xA1);
    port_byte_out(0x20, 0x11);
    port_byte_out(0xA0, 0x11);
    port_byte_out(0x21, 0x20);
    port_byte_out(0xA1, 0x28);
    port_byte_out(0x21, 0x04);
    port_byte_out(0xA1, 0x02);
    port_byte_out(0x21, 0x01);
    port_byte_out(0xA1, 0x01);
    port_byte_out(0x21, a1);
    port_byte_out(0xA1, a2);
    idt_set_gate( 0, (uint32_t)_isr0 , 0x08, 0x8E);
    idt_set_gate( 1, (uint32_t)_isr1 , 0x08, 0x8E);
    idt_set_gate( 2, (uint32_t)_isr2 , 0x08, 0x8E);
    idt_set_gate( 3, (uint32_t)_isr3 , 0x08, 0x8E);
    idt_set_gate( 4, (uint32_t)_isr4 , 0x08, 0x8E);
    idt_set_gate( 5, (uint32_t)_isr5 , 0x08, 0x8E);
    idt_set_gate( 6, (uint32_t)_isr6 , 0x08, 0x8E);
    idt_set_gate( 7, (uint32_t)_isr7 , 0x08, 0x8E);
    idt_set_gate( 8, (uint32_t)_isr8 , 0x08, 0x8E);
    idt_set_gate( 9, (uint32_t)_isr9 , 0x08, 0x8E);
    idt_set_gate( 10, (uint32_t)_isr10 , 0x08, 0x8E);
    idt_set_gate( 11, (uint32_t)_isr11 , 0x08, 0x8E);
    idt_set_gate( 12, (uint32_t)_isr12 , 0x08, 0x8E);
    idt_set_gate( 13, (uint32_t)_isr13 , 0x08, 0x8E);
    idt_set_gate( 14, (uint32_t)_isr14 , 0x08, 0x8E);
    idt_set_gate( 15, (uint32_t)_isr15 , 0x08, 0x8E);
    idt_set_gate( 16, (uint32_t)_isr16 , 0x08, 0x8E);
    idt_set_gate( 17, (uint32_t)_isr17 , 0x08, 0x8E);
    idt_set_gate( 18, (uint32_t)_isr18 , 0x08, 0x8E);
    idt_set_gate( 19, (uint32_t)_isr19 , 0x08, 0x8E);
    idt_set_gate( 20, (uint32_t)_isr20 , 0x08, 0x8E);
    idt_set_gate( 21, (uint32_t)_isr21 , 0x08, 0x8E);
    idt_set_gate( 22, (uint32_t)_isr22 , 0x08, 0x8E);
    idt_set_gate( 23, (uint32_t)_isr23 , 0x08, 0x8E);
    idt_set_gate( 24, (uint32_t)_isr24 , 0x08, 0x8E);
    idt_set_gate( 25, (uint32_t)_isr25 , 0x08, 0x8E);
    idt_set_gate( 26, (uint32_t)_isr26 , 0x08, 0x8E);
    idt_set_gate( 27, (uint32_t)_isr27 , 0x08, 0x8E);
    idt_set_gate( 28, (uint32_t)_isr28 , 0x08, 0x8E);
    idt_set_gate( 29, (uint32_t)_isr29 , 0x08, 0x8E);
    idt_set_gate( 30, (uint32_t)_isr30 , 0x08, 0x8E);
    idt_set_gate( 31, (uint32_t)_isr31 , 0x08, 0x8E);
    idt_set_gate( 32, (uint32_t)_irq0 , 0x08, 0x8E);
    idt_set_gate( 33, (uint32_t)_irq1 , 0x08, 0x8E);
    idt_set_gate( 34, (uint32_t)_irq2 , 0x08, 0x8E);
    idt_set_gate( 35, (uint32_t)_irq3 , 0x08, 0x8E);
    idt_set_gate( 36, (uint32_t)_irq4 , 0x08, 0x8E);
    idt_set_gate( 37, (uint32_t)_irq5 , 0x08, 0x8E);
    idt_set_gate( 38, (uint32_t)_irq6 , 0x08, 0x8E);
    idt_set_gate( 39, (uint32_t)_irq7 , 0x08, 0x8E);
    idt_set_gate( 40, (uint32_t)_irq8 , 0x08, 0x8E);
    idt_set_gate( 41, (uint32_t)_irq9 , 0x08, 0x8E);
    idt_set_gate( 42, (uint32_t)_irq10 , 0x08, 0x8E);
    idt_set_gate( 43, (uint32_t)_irq11 , 0x08, 0x8E);
    idt_set_gate( 44, (uint32_t)_irq12 , 0x08, 0x8E);
    idt_set_gate( 45, (uint32_t)_irq13 , 0x08, 0x8E);
    idt_set_gate( 46, (uint32_t)_irq14 , 0x08, 0x8E);
    idt_set_gate( 47, (uint32_t)_irq15, 0x08, 0x8E);


    _idt_flush((uint32_t)&idt_ptr);
}