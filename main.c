#include <stdio.h>
#include "ds6502.h"
// test
#include "ds6502/actions/action_queue.h"

void test1(ds6502_cpu* cpu) {}
void test2(ds6502_cpu* cpu) {}
void test3(ds6502_cpu* cpu) {}

int main() {

    ds6502_cpu* cpu = NULL;
    if (!ds6502_new(&cpu)) {

    }
    ds6502_free(&cpu);
    return 0;
}
