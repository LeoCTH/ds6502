cmake_minimum_required(VERSION 3.17)
project(ds6502 C)

file(GLOB_RECURSE SRCS main.c ds6502.h ds6502/* )
set(CMAKE_C_STANDARD 11)

add_executable(ds6502 ${SRCS})