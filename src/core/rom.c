#include <nes/rom.h> 

bool nes_header_validate(nes_rom_header_t* hdr) 
{
    if (!hdr)
    {
        NES_LOG_ERROR("Null rom header ptr"); 
        return false; 
    }

    if(memcmp(hdr->signature, NES_SIGN, NES_SIGN_SIZE))
    {
        NES_LOG_ERROR("Invalid nes signature"); 
        return false; 
    }

    if (hdr->prg_pages == 0)
    {
        NES_LOG_ERROR("Zero prg pages"); 
        return false; 
    }

    return true; 
}
