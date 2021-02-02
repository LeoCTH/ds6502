#include <stdlib.h>
#include "array_backed.h"
#include "internal.h"

static ds6502_memtype array_backed = {
        ds_array_backed_mem_free,
        ds_array_backed_mem_read,
        ds_array_backed_mem_write
};

void ds_array_backed_mem_free(ds6502_memory* mem) {
    free(mem->_internal);
    mem->_internal = NULL;
}

u8 ds_array_backed_mem_read(ds6502_memory* mem, u16 addr) {
    // reinterpret_cast moment
    return ((u8*)(mem->_internal))[addr];

}
void ds_array_backed_mem_write(ds6502_memory* mem, u16 addr, u8 val) {
    ((u8*)(mem->_internal))[addr] = val;
}

ds6502_memory* ds_make_array_backed_memory(ds_status_code* status) {
    ds6502_memory* mem = make_blank_memory_(status);
    mem->_internal = calloc(65536, sizeof(u8));
    ALLOC_CHECK(mem->_internal, status);
    mem->_type = &array_backed;
    return mem;
}
