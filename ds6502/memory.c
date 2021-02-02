#include "memory.h"

#include "memory/internal.h"

void ds6502_mem_free(ds6502_memory** mem) {
    (*mem)->_type->free(*mem);
    *mem = NULL;
}
u8 ds6502_mem_read(ds6502_memory* mem, u16 addr) {
    return mem->_type->read(mem, addr);
}
void ds6502_mem_write(ds6502_memory* mem, u16 addr, u8 val) {
    mem->_type->write(mem, addr, val);
}
