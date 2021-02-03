#pragma once
#include "../fwd/cpu.h"

typedef void (*ds_action)(ds6502_cpu*);

typedef struct s_ds_action_node {
    ds_action action;
    struct s_ds_action_node *prev, *next;
} ds_action_node;

typedef struct s_ds_action_queue {
    ds_action_node *first, *last;
} ds_action_queue;

ds_action_queue ds_actq_create();
void ds_actq_enqueue(ds_action_queue* queue, ds_action action);
ds_action ds_actq_dequeue(ds_action_queue* queue);
void ds_actq_empty(ds_action_queue* queue);
