#include "array_backed.h"
#include "internal.h"
#include "../impl/macros.h"

static ds6502_memtype array_backed = {
        ds_array_backed_mem_free,
        ds_array_backed_mem_read,
        ds_array_backed_mem_write
};

void ds_array_backed_mem_free(ds6502_memory* mem) {
    free_then_null(mem->_internal);
}

u8 ds_array_backed_mem_read(ds6502_memory* mem, u16 addr) {
    return reinterpret_cast(mem->_internal, u8*)[addr];

}
void ds_array_backed_mem_write(ds6502_memory* mem, u16 addr, u8 val) {
    reinterpret_cast(mem->_internal, u8*)[addr] = val;
}

ds6502_memory* ds_make_array_backed_memory(ds_status_code* status) {
    ds6502_memory* mem = make_blank_memory_(status);
    mem->_internal = new_array(u8, 65536);
    alloc_check(mem->_internal, status);
    mem->_type = &array_backed;
    return mem;
}
