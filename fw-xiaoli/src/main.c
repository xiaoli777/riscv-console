#include <stdint.h>

volatile int global = 42;
volatile uint32_t controller_status = 0;

volatile char *VIDEO_MEMORY = (volatile char *)(0x50000000 + 0xFE800);
int main() {
    int a = 4;
    int b = 12;
    int last_global = 42;
    int x_pos = 36*32-32;

    for(int i=0;i<32;i++){
        for(int j=0;j<(32-i);j++){
            VIDEO_MEMORY[i*64+j] = '*';
            VIDEO_MEMORY[i*64+63-j] = '*';
        }
    }

    while (1) {
        int c = a + b + global;
        if(global != last_global){
            if(controller_status){
                // VIDEO_MEMORY[x_pos] = '*';
                if(controller_status & 0x1){
                    if(x_pos & 0x3F){
                        x_pos--;
                        VIDEO_MEMORY[x_pos] = '<';
                    }
                }
                else if(controller_status & 0x2){
                    if(x_pos >= 0x40){
                        x_pos -= 0x40;
                        VIDEO_MEMORY[x_pos] = '^';
                    }
                }
                else if(controller_status & 0x4){
                    if(x_pos < 0x8C0){
                        x_pos += 0x40;
                        VIDEO_MEMORY[x_pos] = 'v';
                    }
                }
                else if(controller_status & 0x8){
                    if((x_pos & 0x3F) != 0x3F){
                        x_pos++;
                        VIDEO_MEMORY[x_pos] = '>';
                    }
                }
                else if(controller_status & 0x10){
                    VIDEO_MEMORY[x_pos] = 'u';
                }
                else if(controller_status & 0x20){
                    VIDEO_MEMORY[x_pos] = 'i';
                }
                else if(controller_status & 0x40){
                    VIDEO_MEMORY[x_pos] = 'j';
                }
                else if(controller_status & 0x80){
                    VIDEO_MEMORY[x_pos] = 'k';
                }
                else{

                }
                // VIDEO_MEMORY[x_pos] = 'X';
            }
            last_global = global;
        }
    }
    return 0;
}
