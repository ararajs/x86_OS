uint32_t tick = 0;
static void timer_callback (registers_t reg){
    tick++;
    if (tick%18 == 0){
        print("Hi!\n");
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
