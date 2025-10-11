#ifndef NES_BUS_H
#define NES_BUS_H

#include <nes/common.h> 

typedef struct nes_machine nes_machine_t;

#define NES_RAM_SIZE    0x0800

typedef struct nes_bus {
    uint8_t ram[NES_RAM_SIZE];
    nes_machine_t *machine; 
} nes_bus_t; 

void nes_bus_init(nes_bus_t *bus, nes_machine_t *machine);

#endif
