#include <stdlib.h>
#include "internal.h"
#include "../impl/macros.h"

ds6502_memory* make_blank_memory_(ds_status_code* status) {
    ds6502_memory* memory = new(ds6502_memory);
    alloc_check(memory, status);
    return memory;
}