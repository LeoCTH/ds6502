#pragma once

typedef enum {
    DS_FINE,        // everything is fine
    DS_OOM,         // out of memory
    DS_INVOPC       // invalid opcode

} ds_status_code;

#define ALLOC_CHECK(obj, status_out) if (!(obj)) *status_out = DS_OOM