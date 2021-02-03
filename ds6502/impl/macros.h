#pragma once
#include <stdlib.h>
#include <stddef.h>

// internal cursed macros
#define new(type) malloc(sizeof(type))
#define new_array(type, num) calloc(num, sizeof(type))
#define alloc_check(obj, status_out) if (!(obj)) *status_out = DS_OOM

// yeef
#define reinterpret_cast(obj, type) ((type) (obj))

#define free_then_null(ptr) free(ptr); ptr = NULL;