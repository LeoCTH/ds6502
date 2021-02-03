#include <stdlib.h>
#include "cpu.h"
#include "memory/array_backed.h"
#include "impl/macros.h"

ds6502_cpu* ds6502_init(ds6502_cpu* cpu) {
    cpu->a = cpu->x = cpu->y = cpu->sp = cpu->pc = 0;
    cpu->status_code = DS_FINE;
    cpu->ps = 0b00100000; // set the unused bit, probably ub
    cpu->bus = (ds6502_bus){0, 0, false, ds_make_array_backed_memory(&cpu->status_code)};
    cpu->action_queue = ds_actq_create();
    return cpu;
}

ds6502_cpu* ds6502_clean(ds6502_cpu* cpu) {
    ds6502_mem_free(&cpu->bus.memory);
    ds_actq_empty(&cpu->action_queue);
    return cpu;
}

ds_status_code ds6502_new(ds6502_cpu** cpu) {
    *cpu = new(ds6502_cpu);
    ds_status_code status = DS_FINE;
    alloc_check(*cpu, &status);
    // do not initialize if some error happened
    if (!status) ds6502_init(*cpu);
    return status;
}

void ds6502_free(ds6502_cpu** cpu) {
    ds6502_clean(*cpu);
    free_then_null(*cpu);
}

void ds6502_clock(ds6502_cpu* cpu, u32 cycles) {
    while (cycles) {
        ds_action action; void* operand;
        ds_actq_dequeue(&cpu->action_queue, &action, &operand);
        action(cpu, operand);
        cycles--;
    }
}