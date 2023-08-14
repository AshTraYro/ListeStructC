#ifndef STACKLIST_H
#define STACKLIST_H
#pragma once

typedef struct node_sl
{
    char name[32];
    struct node_sl* next;
}node_sl;


typedef struct stack_list
{
    int size;
    node_sl* head;
    //node_sl* top;
    //node_sl* tail;
}stack_list;

void init_stack_list(stack_list* list);

stack_list* create_stack_list();

void push_stack_list(stack_list* list, char new_name[]);

void print_stack_list(stack_list* list);

node_sl* pop_stack_list(stack_list* list);

void free_stack_list(stack_list* list);

unsigned int size_stack_list(stack_list* list);

char* top_elem_stack_list(stack_list* list);

#endif