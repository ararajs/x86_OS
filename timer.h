uint32_t tick = 0;
static void timer_callback (registers_t reg){
    tick++;
    //print_c('I', 0, 0, COLOR, 1);
    print("Ticks\n");
    if (tick == 18){
        print("hi!\n");
        irq_handlers[reg.int_no] = 0;
    }
}

void init_timer (uint32_t freq){


    register_irq_handler(32, &timer_callback);

    uint32_t divisor = 1193180/freq;

    port_byte_out(0x43, 0x36);

    uint8_t l = (uint8_t) (divisor &0xFF);
    uint8_t h = (uint8_t) ((divisor >> 8) & 0xFF);

    port_byte_out(0x40, l);
    port_byte_out(0x40, h);
}
