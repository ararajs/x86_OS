#define IRQ0 32
#define IRQ1 33
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47




typedef struct registers
{
   uint32_t ds;                
   uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; 
   uint32_t int_no, err_code;   
   uint32_t eip, cs, eflags, useresp, ss; 
} registers_t;

typedef void (*isr_t) (registers_t);

isr_t irq_handlers[256];

void register_irq_handler(uint8_t n, isr_t handler){
    irq_handlers[n] = handler;
}

void _irq_handler(registers_t reg)
{
   if (reg.int_no >= 40){
    port_byte_out(0xA0, 0x20);
   }
   port_byte_out(0x20, 0x20);
   if (irq_handlers[reg.int_no]!=0){
       isr_t handler = irq_handlers[reg.int_no];
       handler(reg);
       //To do, custom handlers for other irqs if needed.
   }
} 




void _isr_handler(registers_t reg)
{
   print("Interrupted recieved\n");
} 