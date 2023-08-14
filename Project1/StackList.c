#include "StackList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void init_stack_list(stack_list* list)
{
    list->size = 0;
    list->head = malloc(sizeof(node_sl));
    list->head = NULL;

}

unsigned int size_stack_list(stack_list* list)
{
    if (list->head == NULL || list->size <= 0)
    {
        printf("\nList is empty");
        return 0;
    }
    else
    {
        return list->size;
    }
}

char* top_elem_stack_list(stack_list* list)
{
    return list->head->name;
}

stack_list* create_stack_list()
{
    int list_size;
    char a[10];
    printf("\nHow many items do you wish to have in your list? :: ");
    //scanf("%d",&list_size);
    fgets(a, sizeof a, stdin);
    list_size = atoi(a);

    stack_list* list = malloc(sizeof(stack_list));
    list->head = NULL;
    list->size = list_size;

    node_sl* p = NULL;

    for (int i = 0; i < list->size; i++)
    {
        node_sl* temp = malloc(sizeof(node_sl));
        temp->next = NULL;
        printf("\nType in the name for the person number %d from the list: ", i + 1);

        fgets(temp->name, sizeof temp->name, stdin);
        temp->name[strcspn(temp->name, "\n")] = 0;

        if (list->head == NULL)
        {
            list->head = temp;
            p = temp;
        }
        else
        {
            list->head = temp;
            list->head->next = p;
            p = temp;
        }
    }

    return list;
}

//We consider last inserted element in the list to be on position 0. So if push one element we will add it in 1st position in the list, replace the head.

void push_stack_list(stack_list* list, char new_name[])
{
    node_sl* newNode;
    while (1) {
        newNode = malloc(sizeof(node_sl));
        if (newNode != NULL) {
            break;
        }
    }
    newNode->next = NULL;
    strcpy_s(newNode->name, sizeof newNode->name, new_name);

    if (list->head == NULL)
    {
        list->head = newNode;
        list->size++;

    }

    else
    {
        newNode->next = list->head;
        list->head = newNode;
        list->size++;

    }
}

//We consider last inserted element in the list to be on position 0. So if we pop one element we will we remove the head.

node_sl* pop_stack_list(stack_list* list)
{
    node_sl* p = list->head;

    if (p == NULL || list == NULL)
    {
        printf("\nWarning: The list is empty.\nAn element cannot be removed from an empty list.\n");
        return NULL;
    }


    else
    {
        list->head = list->head->next;
        list->size--;
        return p;


    }
}

void free_stack_list(stack_list* list)
{
    if (list != NULL)
    {
        node_sl* curent = list->head;
        while (curent != NULL)
        {
            node_sl* aux = curent;

            curent = curent->next;
            free(aux);
            aux = NULL;
        }
    }

    init_stack_list(list);
}



void print_stack_list(stack_list* list)
{
    if (list->head == NULL || list->size <= 0 || list == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        node_sl* p = list->head;
        printf("\nList contains the following elements: ");
        while (p->next != NULL)
        {
            printf("%s, ", p->name);
            p = p->next;

        }
        printf("%s.", p->name);
    }

}