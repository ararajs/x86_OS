void read_time_cmos(){
    uint8_t output_sec, output_min, output_hr;
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
        : "=a" (output_min)
    );
    __asm__ __volatile__ (
        //"cli\n\t"
        "mov $0x84, %%al \n\t"
        "out %%al, $0x70 \n\t"
        "in $0x71, %%al \n\t"
        //"sti\n\t"
        //"cli"
        //"mov al, output"
        : "=a" (output_hr)
    );
    int tens_number_s = output_sec >> 4;
    int units_number_s = output_sec & 0x0F;
    int tens_number_m = output_min >> 4;
    int units_number_m = output_min & 0x0F;
    int tens_number_h = output_hr >> 4;
    int units_number_h = output_hr & 0x0F;
    print_c(*(table + tens_number_h),0,0, 0x02,0);
    print_c(*(table + units_number_h),1,0, 0x02,0);
    print_c(':',2,0, 0x02,0);
    print_c(*(table + tens_number_m),3,0, 0x02,0);
    print_c(*(table+units_number_m),4,0, 0x02,0);
    print_c(':',5,0, 0x02,0);
    print_c(*(table + tens_number_s),6,0,0x02,0);
    print_c(*(table+units_number_s),7,0,0x02,0);   
}

//Time is in hexadecimal coded decimal -> time 15 comes out as 0x15 -> Convert 