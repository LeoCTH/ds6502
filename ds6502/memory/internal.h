#pragma once
#include "../memory.h"
#include "../error_checking.h"

// internal impl! :tiny_potato:
// do *not* access this please thank
struct s_ds6502_memory_ {
    void *_internal;
    ds6502_memtype *_type;
};

ds6502_memory* make_blank_memory_(ds_status_code* status);