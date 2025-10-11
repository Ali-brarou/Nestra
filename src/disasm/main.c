#include <nes/disasm.h> 
#include <nes/machine.h> 
#include <stdio.h> 

int main(int argc, char *argv[])
{
    nes_machine_t machine; 
    nes_hooks_t hooks; 

    nes_machine_init(&machine, &hooks, NULL); 
    return 0; 
}
