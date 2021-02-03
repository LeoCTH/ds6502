#pragma once

typedef enum e_ds_status_code {
    DS_FINE,        // everything is fine
    DS_OOM,         // out of memory
    DS_INVOPC       // invalid opcode

} ds_status_code;
