#include <stdio.h>
#include "ds6502.h"

int main() {
    ds6502_cpu* cpu = NULL;
    if (!ds6502_new(&cpu)) {

    }
    ds6502_free(&cpu);
    return 0;
}
