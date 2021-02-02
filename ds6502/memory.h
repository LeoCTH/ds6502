#pragma once

#include "types.h"

// haha hidden impl :tiny_potato:
typedef struct s_ds6502_memory_ ds6502_memory;

typedef struct {
    void (*const free)(ds6502_memory*);
    u8   (*const read)(ds6502_memory*, u16);
    void (*const write)(ds6502_memory*, u16, u8);
} ds6502_memtype;

// wrappers
void ds6502_mem_free (ds6502_memory** mem);
u8   ds6502_mem_read (ds6502_memory* mem, u16 addr);
void ds6502_mem_write(ds6502_memory* mem, u16 addr, u8 val);
