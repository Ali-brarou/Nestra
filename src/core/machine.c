#include <nes/machine.h> 
#include <nes/common.h> 

int nes_machine_init(nes_machine_t *machine, nes_hooks_t *hooks, void *ctx)
{
    if (!machine)
    {
        NES_LOG_ERROR("Null machine ptr\n"); 
        return -1; 
    }
    if (!hooks)
    {
        NES_LOG_ERROR("Null hooks ptr"); 
        return -1; 
    }

    machine->hooks      = hooks; 
    machine->hooks_ctx  = ctx; 
#ifdef NES_EMULATOR
    nes_cpu_init(&machine->cpu, machine); 
#endif

    return 0; 
}
