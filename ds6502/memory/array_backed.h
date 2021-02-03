#pragma once
#include "../memory.h"
#include "../error_checking.h"

void ds_array_backed_mem_free (ds6502_memory* mem);
u8   ds_array_backed_mem_read (ds6502_memory* mem, u16 addr);
void ds_array_backed_mem_write(ds6502_memory* mem, u16 addr, u8 val);

// returns NULL and sets an error with `status` should an error occur
// otherwise returns a new ds6502_memory object with status set to DS_FINE
ds6502_memory* ds_make_array_backed_memory(ds_status_code* status ///<[out]
);