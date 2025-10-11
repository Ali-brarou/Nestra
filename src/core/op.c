#include <nes/machine.h> 
#include <string.h> 

const nes_opcode_t nes_op_table[NES_OP_COUNT] = {
    [0x0] = {OP_OFF, 0x0, "BRK", ADDR_IMP, 0, 7}, 
}; 
