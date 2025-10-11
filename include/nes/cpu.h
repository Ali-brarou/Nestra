#ifndef NES_CPU_H
#define NES_CPU_H

#include <nes/common.h> 
#include <nes/inst.h> 

/* forward declaration */
typedef struct nes_machine nes_machine_t;

typedef enum nes_status_flag {
    NES_FLAG_C = 1 << 0,
    NES_FLAG_Z = 1 << 1,
    NES_FLAG_I = 1 << 2,
    NES_FLAG_D = 1 << 3,
    NES_FLAG_B = 1 << 4,
    NES_FLAG_UNUSED = 1 << 5,
    NES_FLAG_V = 1 << 6, 
    NES_FLAG_N = 1 << 7
} nes_status_flag_t; 

typedef struct nes_cpu {
    uint8_t sp;         /* stack pointer    */  
    uint16_t pc;        /* program counter  */  
    uint8_t a, x, y;    /* registers        */ 
    uint8_t p;          /* process status   */  
    nes_machine_t *machine; 
} nes_cpu_t; 

static inline void nes_cpu_set_flag(nes_cpu_t* cpu, nes_status_flag_t flag)
{
    cpu->p |= flag; 
}

static inline void nes_cpu_clear_flag(nes_cpu_t* cpu, nes_status_flag_t flag)
{
    cpu->p &= ~flag; 
}

static inline uint8_t nes_cpu_get_flag(nes_cpu_t* cpu, nes_status_flag_t flag)
{
    return cpu->p & flag; 
}

void nes_cpu_init(nes_cpu_t *cpu, nes_machine_t *machine); 
void nes_cpu_step(nes_cpu_t *cpu, nes_inst_t *inst); 

#endif
