#include "cpu.h"
#include "memory/array_backed.h"
#include <stdlib.h>

ds6502_cpu* ds6502_init(ds6502_cpu* cpu) {
    cpu->a = cpu->x = cpu->y = cpu->sp = cpu->pc = 0;
    cpu->status_code = DS_FINE;
    cpu->ps = 0b00100000; // set the unused bit, probably ub
    cpu->memory = ds_make_array_backed_memory(&cpu->status_code);
    return cpu;
}

ds6502_cpu* ds6502_clean(ds6502_cpu* cpu) {
    ds6502_mem_free(&cpu->memory);
    return cpu;
}

ds_status_code ds6502_new(ds6502_cpu** cpu) {
    *cpu = malloc(sizeof(ds6502_cpu));
    ds_status_code status = DS_FINE;
    ALLOC_CHECK(*cpu, &status);
    // do not initialize if some error happened
    if (!status) ds6502_init(*cpu);
    return status;
}

void ds6502_free(ds6502_cpu** cpu) {
    ds6502_clean(*cpu);
    free(*cpu);
    *cpu = NULL;
}