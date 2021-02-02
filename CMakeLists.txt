cmake_minimum_required(VERSION 3.17)
project(dipshit_6502 C)

set(CMAKE_C_STANDARD 11)

add_executable(dipshit_6502 main.c ds6502/cpu.h ds6502.h ds6502/types.h ds6502/memory.h ds6502/memory.c ds6502/memory/array_backed.h ds6502/memory/array_backed.c ds6502/memory/internal.h ds6502/cpu.c ds6502/memory/internal.c ds6502/error_checking.h)