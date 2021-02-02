#pragma once

enum e_ds_status_code {
    DS_FINE,        // everything is fine
    DS_OOM,            // out of memory


};
// 'Forward references to 'enum' types are a Microsoft extension'
// thank you c11 standard very cool
typedef enum e_ds_status_code ds_status_code;

#define ALLOC_CHECK(obj, status_out) if (!(obj)) *status_out = DS_OOM