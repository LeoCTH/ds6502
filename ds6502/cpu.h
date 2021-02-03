#pragma once

#include <stdbool.h>
#include "fwd/cpu.h"
#include "types.h"
#include "memory.h"
#include "error_checking.h"
#include "actions/action_queue.h"
#include "bus.h"

struct s_ds6502_cpu {
    u8 a, x, y, sp;
    u16 pc;
    union {
        u8 ps;
        struct {
            bool ps_carry: 1;
            bool ps_zero: 1;
            bool ps_irq_enabled: 1;
            bool ps_decimal: 1;
            bool ps_brk: 1;
            const bool _ps_unused: 1; // = 1
            bool ps_overflow: 1;
            bool ps_negative: 1;
        };
    };
    ds6502_bus bus;
    ds_status_code status_code;
    ds_action_queue action_queue;
};

// new needs a status code because the cpu alloc might fail.
// this is assuming that cpu != NULL
ds6502_cpu* ds6502_init(ds6502_cpu* cpu);
ds6502_cpu* ds6502_clean(ds6502_cpu* cpu);

ds_status_code ds6502_new(ds6502_cpu** cpu);
void ds6502_free(ds6502_cpu** cpu);

void ds6502_reset(ds6502_cpu* cpu);
void ds6502_clock(ds6502_cpu* cpu, u32 cycles);
