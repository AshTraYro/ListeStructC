#ifndef DOUBLYLIKEDLIST_H
#define DOUBLYLIKEDLIST_H
#pragma once

typedef struct node_dll
{
    char name[32];
    struct node_dll* next;
    struct node_dll* previous;
}node_dll;


typedef struct doubly_linked_list
{
    int size;
    node_dll* head;
}doubly_linked_list;

void init_doubly_linked_list(doubly_linked_list* list);

doubly_linked_list* create_doubly_linked_list();

void add_nth_elem_doubly_linked_list(doubly_linked_list* list, int n, char new_name[]);

void print_doubly_linked_list(doubly_linked_list* list);

node_dll* remove_node_doubly_linked_list(doubly_linked_list* list, int n);

void free_doubly_linked_list(doubly_linked_list* list);

unsigned int size_doubly_linked_list(doubly_linked_list* list);

#endif

