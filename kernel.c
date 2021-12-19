#include "type.h"
#include "io.h"
#include "screen.h"
#include "read_from_cmos.h"

void _main(){;
    clear_screen();
    uint8_t* string = "Welcome to TryOS\n";
    //uint8_t* string1 = "Nice to meet you.";
    print_at(string,12,32);
    //print_at(string1,2, 32);
    disable_cursor();
    while (1){
        read_time_cmos();
    }
}

