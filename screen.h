
//Presets for VGA
#define VIDEO_ADDR 0xb8000
#define MAX_ROWS 25
#define MAX_COL 80
#define COLOR 0xF2

//I/O registers for the VGA Output
#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5


void disable_cursor(){
    port_byte_out(0x3D4, 0x0A);
    port_byte_out(0x3D5, 0x20);
}

void enable_cursor(uint8_t cursor_start, uint8_t cursor_end){

	port_byte_out(0x3D4, 0x0A);
	port_byte_out(0x3D5, (port_byte_in(0x3D5) & 0xC0) | cursor_start);
	port_byte_out(0x3D4, 0x0B);
	port_byte_out(0x3D5, (port_byte_in(0x3D5) & 0xE0) | cursor_end);
}

int get_screen_offset(int col, int row){
    return (80*row + col) * 2;
}

int get_cursor(){
    port_byte_out(REG_SCREEN_CTRL, 14);
    int offset = port_byte_in(REG_SCREEN_DATA) << 8;
    port_byte_out(REG_SCREEN_CTRL,15);
    offset += port_byte_in(REG_SCREEN_DATA);
    return offset*2;
}

void set_cursor(int offset){
    offset /= 2;
    int offset_hb = (offset >> 8 & 0xFF) ;
    int offset_lb = (offset & 0xFF);
    port_byte_out(REG_SCREEN_CTRL, 15);
    port_byte_out(REG_SCREEN_DATA, offset_lb);
    port_byte_out(REG_SCREEN_CTRL, 14);
    port_byte_out(REG_SCREEN_DATA, offset_hb);
}

int handle_scrolling(int offset){
    if (offset < MAX_ROWS*MAX_COL*2){
        return offset;
    }

    for (int i = 1; i < MAX_ROWS; i++){
        memcpy((uint8_t*) (get_screen_offset(0,i) + VIDEO_ADDR) ,(uint8_t*) (get_screen_offset(0,i-1) + VIDEO_ADDR), MAX_COL*2);
    }

    uint8_t* last_line = (uint8_t*) (get_screen_offset(0, MAX_ROWS-1) + VIDEO_ADDR);
    for (int i = 0; i < MAX_COL; i++){
        last_line[2*i] = 0;
        last_line[2*i + 1] = COLOR;
    }

    offset -= 2*MAX_COL;
    return offset;
}

void print_c(char input, int col, int row, char att_byte){
    volatile unsigned char* vid_memory = (unsigned char*) VIDEO_ADDR;
    if (!att_byte){
        att_byte = COLOR;
    }
    int offset;
    if (col >= 0 && row >=0){
        offset = get_screen_offset(col, row);
    }
    else {
        offset = get_cursor();
    }

    if (input == '\n'){
        int rows = offset/(2*MAX_COL);
        offset = get_screen_offset(79, rows);
    } else {
        *(vid_memory+offset) = input;
        *(vid_memory+offset+1) = att_byte;
    }

    offset += 2;
    offset = handle_scrolling(offset);
    set_cursor(offset);
}

void print_at(char* msg, int row, int col){
    if (col >= 0 && row >= 0){
        set_cursor(get_screen_offset(col, row));
    }
    
    int c = 0;
    while (*(msg +c) != 0){
        print_c(*(msg+c), col+c, row, COLOR);
        c++;
    }
}

void print(char* message){
    print_at(message, -1, -1);
}

void clear_screen(){
    for (int row = 0; row < MAX_ROWS; row++){
        for (int col = 0; col < MAX_COL; col++){
            print_c(' ', col, row, COLOR);
        }
    }
    set_cursor(get_screen_offset(0,0));
}



