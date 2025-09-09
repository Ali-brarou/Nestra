#ifndef NES_ROM_H
#define NES_ROM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <nes/common.h> 
#include <assert.h> 
#include <stdint.h> 
#include <stdbool.h> 
#include <string.h> 

#define NES_SIGN        "NES\x1A"
#define NES_SIGN_SIZE   4
#define NES_ZERO_SIZE   5
#define NES_HEADER_SIZE 16

typedef struct nes_rom_header {
    uint8_t signature[NES_SIGN_SIZE]; 
    uint8_t prg_pages;  
    uint8_t chr_pages; 
    uint8_t flags6; 
    uint8_t flags7; 
    uint8_t prg_ram_size; 
    uint8_t flags9; 
    uint8_t flags10; 
    uint8_t zero[NES_ZERO_SIZE];  /* unused */ 
} nes_rom_header_t; /* TODO: Not sure if PACKED is needed; all fields are 1 byte */ 

NES_STATIC_ASSERT(sizeof(nes_rom_header_t) == 16, "NES header must be 16 bytes");

static inline bool nes_header_validate(nes_rom_header_t* hdr) 
{
    assert(hdr); 
    if(memcmp(hdr->signature, NES_SIGN, NES_SIGN_SIZE))
        return false; 

    for (size_t i = 0; i < NES_ZERO_SIZE; i++) 
    {
        if (hdr->zero[i]) return false; 
    } 

    if (!hdr->prg_pages) return false; 

    return true; 
}

#ifdef __cplusplus
}
#endif

#endif
