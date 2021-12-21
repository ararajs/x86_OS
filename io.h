
uint8_t port_byte_in(uint16_t port){
    //Input from port, stored at result;
    uint8_t result;
    __asm__ __volatile__("in %%dx, %%al" 
            : "=a" (result)
            : "d" (port)
            );
    return result;
}

void port_byte_out (uint16_t port ,uint8_t data){
    __asm__ __volatile__("out %%al, %%dx" 
            :
            : "a" (data),"d" (port)
            );
}

uint16_t port_word_in (uint16_t port){
    uint16_t result;
    __asm__ __volatile__("in %%dx, %%ax" 
            : "=a" (result)
            : "d" (port)
            );
    return result;
}

void port_word_out (uint16_t port, uint16_t data){
    __asm__ __volatile__("out %%ax, %%dx" 
            : 
            : "a" (data),"d" (port)
            );
}

void mem_cpy(uint8_t* source, uint8_t* dest, int nb){
    for (int i = 0; i < nb; i++){
        *(dest+i) = *(source+i);
    }
}

void  *memset(void *b, int c, int len)
{
  unsigned char *p = b;
  while(len > 0)
    {
      *p = c;
      p++;
      len--;
    }
  return(b);
}

void enable(){
  __asm__ __volatile__ ("sti");
}

void disable (){
  __asm__ __volatile__ ("cli");
}