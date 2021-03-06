#include "action_queue.h"
#include "../impl/macros.h"

ds_action_queue ds_actq_create() {
    return (ds_action_queue){.first = NULL, .last = NULL};
}

void ds_actq_enqueue(ds_action_queue* queue, ds_action action, void* operand) {
    ds_action_node* node = new(ds_action_node);
    node->action = action;
    node->operand = operand;
    if (queue->last) {
        // append
        queue->last->next = node;
        node->prev = queue->last;
        node->next = NULL;
        queue->last = node;
    }
    else {
        queue->first = queue->last = node;
        node->prev = node->next = NULL;
    }
}

void ds_actq_dequeue(ds_action_queue* queue, ds_action* action, void** operand) {
    if (queue->first) {
        ds_action_node* node = queue->first;
        if (!node->next) {
            queue->first = queue->last = NULL;
        }
        else queue->first = node->next;
        *action = node->action;
        *operand = node->operand;
        free_then_null(node);
    }
}

void ds_actq_empty(ds_action_queue* queue) {
    ds_action_node** node = &queue->first;
    while (*node) {
        ds_action_node* next_node = (*node)->next;
        free_then_null(*node);
        node = &next_node;
    }
    queue->first = queue->last = NULL;
}