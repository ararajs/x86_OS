uint8_t detected = 1;
uint16_t column = 24;
uint16_t row = 0;

uint8_t kmap [128] =  {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', 
  '9', '0', '-', '=', 'b',    
  't',                
  'q', 'w', 'e', 'r',   
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', 'n',
    0,                  
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',    
 '`', '`',   0,                
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',                    /* 49 */
  'm', ',', '.', '/',   0,                              /* Right shift */
  '*',
    0,  /* Alt */
  ' ',  /* Space bar */
    0,  /* Caps lock */
    0,  /* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,  /* < ... F10 */
    0,  /* 69 - Num lock*/
    0,  /* Scroll Lock */
    0,  /* Home key */
    0,  /* Up Arrow */
    0,  /* Page Up */
  '-',
    0,  /* Left Arrow */
    0,
    0,  /* Right Arrow */
  '+',
    0,  /* 79 - End key*/
    0,  /* Down Arrow */
    0,  /* Page Down */
    0,  /* Insert Key */
    0,  /* Delete Key */
    0,   0,   0,
    0,  /* F11 Key */
    0,  /* F12 Key */
    0,  /* All other keys are undefined */
};

static void kb_callback (registers_t reg){
    print_at("Input detected", 0,0);
    detected = 1;
}


void init_kb (){
    set_ps2();
    register_irq_handler(IRQ1, &kb_callback);
}

void take_input(){
    uint8_t input = port_byte_in(0x60);
    if (detected && input){
        print_c(kmap[input], column, row, 0xF2, 1);
        column++;
        if (column == 79){
            row++;
            column = 24;
        }
        detected = 0;
    }

}