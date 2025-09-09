#ifndef NES_OPS_H
#define NES_OPS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> 

typedef struct nes_opcode {
    uint8_t value; 
    const char *mnemonic; 
} nes_opcode_t; 

#ifdef __cplusplus
}
#endif

#endif
