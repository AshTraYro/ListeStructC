#ifndef CIRCULARLIKEDLIST_H
#define CIRCULARLIKEDLIST_H
#pragma once

typedef struct node_cll
{
    char name[32];
    struct node_cll* next;
}node_cll;


typedef struct circular_linked_list
{
    int size;
    node_cll* head;
}circular_linked_list;

void init_circular_linked_list(circular_linked_list* list);

circular_linked_list* create_circular_linked_list();

void add_nth_elem_circular_linked_list(circular_linked_list* list, int n, char new_name[]);

void print_circular_linked_list(circular_linked_list* list);

node_cll* remove_node_circular_linked_list(circular_linked_list* list, int n);

void free_circular_linked_list(circular_linked_list* list);

unsigned int size_circular_linked_list(circular_linked_list* list);

#endif

