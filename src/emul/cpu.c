#include <nes/machine.h> 
#include <string.h>

void nes_cpu_init(nes_cpu_t *cpu, nes_machine_t *m)
{
    memset(cpu, 0, sizeof(nes_cpu_t)); 
    cpu->machine = m;
}
