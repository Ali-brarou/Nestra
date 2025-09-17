#include <nes/machine.h> 
#include <string.h> 

#define OPCODE_DEF(t, val, mn, am, sz, cyc) \
    do { \
        assert(0 <= val && val < NES_OP_COUNT); \
        t[val] = (nes_opcode_t){OP_OFF, val, mn, am, sz, cyc}; \
    } while (0)

void nes_op_init(nes_opcode_t *op_table)
{
    memset(op_table, 0, NES_OP_COUNT * sizeof(nes_opcode_t)); 
    OPCODE_DEF(op_table, 0x0, "BRK", ADDR_IMP, 0, 7); 
}
