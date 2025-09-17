#ifndef NES_INST_H
#define NES_INST_H

#include <nes/op.h> 

typedef struct nes_inst {
    nes_opcode_t *opcode;  /* points to the nes_opcode_table */ 
    uint16_t addr; 
} nes_inst_t; 

#endif
