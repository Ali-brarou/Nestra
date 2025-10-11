#ifndef NES_HOOKS_H
#define NES_HOOKS_H

typedef struct nes_hooks {
#ifdef NES_EMULATOR
    void (*draw_sprite)(uint8_t sprite_id, void *ctx);
#endif
#ifdef NES_DISSAMBLER
    void (*log_inst)(nes_inst_t* inst, void *ctx);
#endif
} nes_hooks_t;

#endif
