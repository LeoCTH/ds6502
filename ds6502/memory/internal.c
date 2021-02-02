#include <stdlib.h>
#include "internal.h"

ds6502_memory* make_blank_memory_(ds_status_code* status) {
    ds6502_memory* memory = malloc(sizeof(ds6502_memory));
    ALLOC_CHECK(memory, status);
    return memory;
}