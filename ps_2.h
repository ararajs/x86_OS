void set_ps2 (){
    port_byte_out(0x60 , 0xF5); //Disable scanning 
    uint8_t out = port_byte_in(0x60);
    if (out == 0xFA){ //Await ACK == 0xFA
        port_byte_out(0x60, 0xF2); //Identify PS/2 Device Type
        out = port_byte_in(0x60);
        if (out == 0xFA){
            port_byte_out(0x60, 0xF4); //Enable scanning 
        }
    }
}