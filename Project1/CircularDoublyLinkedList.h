#ifndef CIRCULARDOUBLYLIKEDLIST_H
#define CIRCULARDOUBLYLIKEDLIST_H
#pragma once

typedef struct node_cdll
{
    char name[32];
    struct node_cdll* next;
    struct node_cdll* previous;
}node_cdll;


typedef struct circular_doubly_linked_list
{
    int size;
    node_cdll* head;
}circular_doubly_linked_list;

void init_circular_doubly_linked_list(circular_doubly_linked_list* list);

circular_doubly_linked_list* create_circular_doubly_linked_list();

void add_nth_elem_circular_doubly_linked_list(circular_doubly_linked_list* list, int n, char new_name[]);

void print_circular_doubly_linked_list(circular_doubly_linked_list* list);

node_cdll* remove_node_circular_doubly_linked_list(circular_doubly_linked_list* list, int n);

void free_circular_doubly_linked_list(circular_doubly_linked_list* list);

unsigned int size_circular_doubly_linked_list(circular_doubly_linked_list* list);

#endif