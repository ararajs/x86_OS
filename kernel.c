
#include "type.h"
#include "io.h"
#include "screen.h"
#include "read_from_cmos.h"
#include "ps_2.h"
#include "idt.h"
#include "isr.h"
#include "timer.h"

/* TODO
Setup IDT [X]
Ensure IDT and IRQs work [X]
Setup PS/2 Key char capture interface []
*/

void _main(){;
    init_idt();
    set_cursor(0);
    clear_screen();
    //uint8_t* string = "Welcome to TryOS\n";
    //uint8_t* string1 = "Nice to meet you.";
    //print_at(string,12,32);
    //print_at(string1,2, 32);
    //disable_cursor();
    //set_cursor(0x12);
    //
    //set_ps2();
    init_timer(1);
    //_asm__ __volatile__ ("int $0x00");
    //__asm__ __volatile__ ("int $0x03");
    //print_c('E', 9, 0, COLOR,1);
    /*while (1){
        read_time_cmos();
        print_c(port_byte_in(0x60),25,0,COLOR,1);
    }*/
}

