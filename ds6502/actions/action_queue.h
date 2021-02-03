#pragma once
#include "../action.h"

typedef struct s_ds_action_node {
    ds_action action;
    void* operand; // yes yes very safe:tm:
    struct s_ds_action_node *prev, *next;
} ds_action_node;

typedef struct s_ds_action_queue {
    ds_action_node *first, *last;
} ds_action_queue;

ds_action_queue ds_actq_create();
/**
 * @param queue [in]
 * @param action [in]
 * @param operand [in]
 */
void ds_actq_enqueue(ds_action_queue* queue, ds_action action, void* operand);
/**
 * @param queue [in]
 * @param action [out]
 * @param operand [out]
 */
void ds_actq_dequeue(ds_action_queue* queue, ds_action* action, void** operand);
void ds_actq_empty(ds_action_queue* queue);
