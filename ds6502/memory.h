#pragma once

#include "types.h"

/**
 * \brief Conceptually represents the entire memory space
 * addressable by a 6502 processor.
 *
 * \note The concrete definition is <em>encapsulated and inaccessible</em>,
 * as such the handling of modifications to the memory space
 * is entirely implementation defined.
 */
typedef struct s_ds6502_memory ds6502_memory;

typedef struct s_ds6502_memtype {
    void (*const free)(ds6502_memory*);
    u8   (*const read)(ds6502_memory*, u16);
    void (*const write)(ds6502_memory*, u16, u8);
} ds6502_memtype;

// wrappers
/**
 * Cleans and frees the allocated memory used by the
 * memory pointer (`*mem`), then sets it to `NULL`.
 * @param [in] mem a pointer to a memory object
 */
void ds6502_mem_free (ds6502_memory** mem);
u8   ds6502_mem_read (ds6502_memory* mem, u16 addr);
void ds6502_mem_write(ds6502_memory* mem, u16 addr, u8 val);
