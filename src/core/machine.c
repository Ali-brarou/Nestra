#include <nes/machine.h> 

void nes_machine_init(nes_machine_t *machine, nes_hooks_t *hooks, void *ctx)
{
    assert(machine); 
    assert(hooks); 

    machine->hooks      = hooks; 
    machine->hooks_ctx  = ctx; 
    nes_op_init(machine->op_table); 
#ifdef NES_EMULATOR
    nes_cpu_init(&machine->cpu, machine); 
#endif
}
