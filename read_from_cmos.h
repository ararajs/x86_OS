
void read_time_cmos(){
     uint8_t output_sec, output_hr;
    uint8_t* table = "0123456789";
    __asm__ __volatile__ (
        //"cli\n\t"
        "mov $0x80, %%al \n\t"
        "out %%al, $0x70 \n\t"
        "in $0x71, %%al \n\t"
        //"sti\n\t"
        //"cli"
        //"mov al, output"
        : "=a" (output_sec)
    );
    __asm__ __volatile__ (
        //"cli\n\t"
        "mov $0x82, %%al \n\t"
        "out %%al, $0x70 \n\t"
        "in $0x71, %%al \n\t"
        //"sti\n\t"
        //"cli"
        //"mov al, output"
        : "=a" (output_hr)
    );
    int tens_number_s = output_sec >> 4;
    int units_number_s = output_sec & 0x0F;
    int tens_number_h = output_hr >> 4;
    int units_number_h = output_hr & 0x0F;
    print_c(*(table + tens_number_h),0,0, 0x02);
    print_c(*(table+units_number_h),1,0, 0x02);
    print_c(':',2,0, 0x02);
    print_c(*(table + tens_number_s),3,0,0x02);
    print_c(*(table+units_number_s),4,0,0x02);
    
}

//Time is in hexadecimal coded decimal -> time 15 comes out as 0x15 -> Convert 