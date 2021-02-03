#include <stdio.h>
#include "ds6502.h"
// test
#include "ds6502/actions/io.h"
int main() {

    ds6502_cpu* cpu = NULL;
    if (!ds6502_new(&cpu)) {
        // todo (?)
        u16 addr = 0xbf52;
        ds_actq_enqueue(&cpu->action_queue, ds6502_read, &addr);
        ds6502_clock(cpu, 1);
    }
    ds6502_free(&cpu);
    return 0;
}
