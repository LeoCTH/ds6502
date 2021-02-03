#pragma once
#include <stdbool.h>
#include "types.h"
#include "memory.h"

typedef enum e_ds6502_rwmode {
    DS_RW_READ,
    DS_RW_WRITE
} ds6502_rwmode;

typedef struct s_ds6502_bus {
    u16 addr;
    u8 data;
    ds6502_rwmode rw;
    ds6502_memory* memory;
} ds6502_bus;