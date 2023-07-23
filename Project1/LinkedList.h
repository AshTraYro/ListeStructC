#ifndef LIKEDLIST_H
#define LIKEDLIST_H
#pragma once

typedef struct node_ll
{
    char name[32];
    struct node_ll* next;
}node_ll;


typedef struct linked_list
{
    int size;
    node_ll* head;
}linked_list;

void init_linked_list(linked_list* list);

linked_list* create_linked_list();

void add_nth_elem_linked_list(linked_list* list, int n, char new_name[]);

void print_linked_list(linked_list* list);

node_ll* remove_node_linked_list(linked_list* list, int n);

void free_linked_list(linked_list* list);

unsigned int size_linked_list(linked_list* list);

#endif

