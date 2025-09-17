#ifndef NES_OP_H
#define NES_OP_H

#include <nes/common.h> 

#define NES_OP_COUNT 256 

/* forward declaration */ 
typedef struct nes_machine nes_machine_t; 

typedef enum op_status {
    OP_INV = 0,  /* invalid opcode */ 
    OP_OFF,      /* official opcode */  
    OP_UND,      /* unofficial opcode */ 
} op_status_t; 

typedef enum nes_addrmode {
    ADDR_IMP = 0,
    ADDR_IMM, 
    ADDR_ZP, 
    ADDR_ZPX, 
    ADDR_ZPY,
    ADDR_ABS, 
    ADDR_ABX, 
    ADDR_ABY, 
    ADDR_IND, 
    ADDR_INX,
    ADDR_INY, 
    ADDR_REL
} nes_addrmode_t;

typedef struct nes_opcode {
    op_status_t status; 
    uint8_t value; 
    const char *mnemonic; 
    nes_addrmode_t mode; 
    uint8_t size; 
    uint8_t cycles;
} nes_opcode_t; /* nes_opcode will be zeroed if it's illegal */ 

void nes_op_init(nes_opcode_t *op_table); /* must be called before using opcode table */ 

#endif
