#include <stdint.h>

extern uint8_t _etext;
extern uint8_t _data;
extern uint8_t _edata;
extern uint8_t _sdata;
extern uint8_t _esdata;

// Adapted from https://stackoverflow.com/questions/58947716/how-to-interact-with-risc-v-csrs-by-using-gcc-c-code
__attribute__((always_inline)) uint32_t csr_mstatus_read(void){
    uint32_t result;
    asm("csrr %0, mstatus" : "=r"(result));
    return result;
}

__attribute__((always_inline)) void csr_mstatus_write(uint32_t val){
    asm("csrw mstatus, %0" : "=r"(val));
}

__attribute__((always_inline)) void csr_write_mie(uint32_t val){
    asm("csrw mie, %0" : "=r"(val));
}

__attribute__((always_inline)) void csr_enable_interrupts(void){
    asm("csrsi mstatus, 0x8");
}

__attribute__((always_inline)) void csr_disable_interrupts(void){
    asm("csrci mstatus, 0x8");
}

#define MTIME_LOW       (*((volatile uint32_t *)0x40000008))
#define MTIME_HIGH      (*((volatile uint32_t *)0x4000000C))
#define MTIMECMP_LOW    (*((volatile uint32_t *)0x40000010))
#define MTIMECMP_HIGH   (*((volatile uint32_t *)0x40000014))
#define CONTROLLER      (*((volatile uint32_t *)0x40000018))

void init(void){
    uint8_t *Source = &_etext;
    uint8_t *Base = &_data < &_sdata ? &_data : &_sdata;
    uint8_t *End = &_edata > &_esdata ? &_edata : &_esdata;

    while(Base < End){
        *Base++ = *Source++;
    }
    csr_write_mie(0x888);       // Enable all interrupt soruces
    csr_enable_interrupts();    // Global interrupt enable
    MTIMECMP_LOW = 1;
    MTIMECMP_HIGH = 0;
}

extern volatile int global;
extern volatile uint32_t controller_status;

void c_interrupt_handler(void){
    uint64_t NewCompare = (((uint64_t)MTIMECMP_HIGH)<<32) | MTIMECMP_LOW;
    NewCompare += 100;
    MTIMECMP_HIGH = NewCompare>>32;
    MTIMECMP_LOW = NewCompare;
    global++;
    controller_status = CONTROLLER;
}

