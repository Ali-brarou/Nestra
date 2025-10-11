#ifndef NES_MACHINE_H
#define NES_MACHINE_H

#include <nes/common.h> 
#include <nes/hooks.h> 
#include <nes/op.h> 
#include <nes/inst.h> 
#include <nes/cpu.h> 
#include <nes/bus.h> 

typedef struct nes_machine {
    const nes_opcode_t *op_table; /* ptr to opcode table */ 

    nes_hooks_t *hooks; 
    void *hooks_ctx; /* user-defined context */ 

#ifdef NES_EMULATOR
    nes_cpu_t cpu; 
    nes_bus_t bus; 
#endif
} nes_machine_t; 

int nes_machine_init(nes_machine_t *machine, nes_hooks_t *hooks, void *ctx); 

#endif
