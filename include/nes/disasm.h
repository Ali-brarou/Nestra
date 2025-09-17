#ifndef NES_DISASM_H
#define NES_DISASM_H

#include <nes/rom.h> 

void nes_disas_init(void); 

size_t nes_disas(const uint8_t* code); 

#endif
