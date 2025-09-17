#ifndef NES_MACHINE_H
#define NES_MACHINE_H

#include <nes/common.h> 
#include <nes/op.h> 
#include <nes/inst.h> 
#include <nes/cpu.h> 

typedef struct nes_hooks {
#ifdef NES_EMULATOR
    void (*draw_sprite)(uint8_t sprite_id, void *ctx); 
#endif
#ifdef NES_DISSAMBLER
    void (*log_inst)(nes_inst_t* inst, void *ctx); 
#endif
} nes_hooks_t; 

typedef struct nes_machine {
    nes_hooks_t *hooks; 
    void *hooks_ctx;
    nes_opcode_t op_table[NES_OP_COUNT]; 
#ifdef NES_EMULATOR
    nes_cpu_t cpu; 
#endif
} nes_machine_t; 

NES_STATIC_ASSERT(
    sizeof(((nes_machine_t*)0)->op_table)/sizeof(nes_opcode_t) == 256,
    "op_table must be 256 elements"
);

void nes_machine_init(nes_machine_t *machine, nes_hooks_t *hooks, void *ctx); 

#endif
