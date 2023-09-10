#ifndef QUEUELIST_H
#define QUEUELIST_H
#pragma once


typedef struct node_ql
{
    char name[32];
    struct node_ql* next;
}node_ql;

//We consider that the front pointer points to the first element of the linked list and will be the position where we Dequeue (remove elements) - O(1)
//We consider that the rear pointer points to the last element of the linked list and will be the position where we Enqueue (add elements) - O(1)
typedef struct queue_list
{
    int max_size;
    int size;
    node_ql* front;
    node_ql* rear;
}queue_list;

void init_queue_list(queue_list* list);

queue_list* create_queue_list();

void enqueue_queue_list(queue_list* list, char new_name[]);

void print_queue_list(queue_list* list);

node_ql* dequeue_queue_list(queue_list* list);

void free_queue_list(queue_list* list);

unsigned int size_queue_list(queue_list* list);

_Bool is_queue_empty(queue_list* list);

_Bool is_queue_full(queue_list* list);

char* top_elem_queue_list(queue_list* list);

#endif

