#include "io.h"
#include "../cpu.h"
#include "../types.h"
#include "../impl/macros.h"

void ds6502_read(ds6502_cpu* cpu, void* operand) {
    cpu->bus.rw = DS_RW_READ;
    cpu->bus.addr = *reinterpret_cast(operand, u16*);
    // TODO implement open bus when the valid data could not be found
    cpu->bus.data = ds6502_mem_read(cpu->bus.memory, cpu->bus.addr);
}