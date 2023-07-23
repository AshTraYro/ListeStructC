#include "CircularDoublyLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void init_circular_doubly_linked_list(circular_doubly_linked_list* list)
{
    list->size = 0;
    list->head = malloc(sizeof(node_cdll));
    list->head = NULL;

}

unsigned int size_circular_doubly_linked_list(circular_doubly_linked_list* list)
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

circular_doubly_linked_list* create_circular_doubly_linked_list()
{
    int list_size;
    char a[10];
    printf("\nHow many items do you wish to have in your list? :: ");
    //scanf("%d",&list_size);
    fgets(a, sizeof a, stdin);
    list_size = atoi(a);

    circular_doubly_linked_list* list = malloc(sizeof(circular_doubly_linked_list));
    list->head = NULL;
    list->size = list_size;

    node_cdll* p = NULL;

    for (int i = 0; i < list->size; i++)
    {
        node_cdll* temp = malloc(sizeof(node_cdll));
        temp->next = temp;
        temp->previous = temp;
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
            p->next = temp;
            temp->previous = p;
            temp->next = list->head;
            list->head->previous = temp;
            p = temp;
        }
    }

    return list;
}

//We consider 1st element in the list to be on position 0. So if n=0 we add in 1st position in the list, replace the head.
//If we try to add an element to a negative position return error mesage aloang with NULL value.
//If we add an element to a position greater than the number of elements we add the elemnt last in list.
void add_nth_elem_circular_doubly_linked_list(circular_doubly_linked_list* list, int n, char new_name[])
{
    node_cdll* newNode;
    while (1) 
    {
        newNode = malloc(sizeof(node_cdll));
        if (newNode != NULL) 
        {
            break;
        }
    }
    newNode->next = newNode;
    newNode->previous = newNode;
    strcpy_s(newNode->name, sizeof newNode->name, new_name);

    if (n < 0)
    {
        printf("\nA new element cannot be added in a negative position.\n");
        free(newNode);
        newNode = NULL;
    }

    else if (list->head == NULL)
    {
        list->head = newNode;
        list->size++;
    }

    else if (n == 0)
    {
        node_cdll* last = list->head;
        while (last->next != list->head)
        {
            last = last->next;
        }
        newNode->next = list->head;
        list->head->previous = newNode;
        list->head = newNode;
        list->head->previous = last;
        last->next = list->head;
        list->size++;

    }

    else
    {
        node_cdll* p = list->head;
        int i = 1;

        while (p->next != list->head && i < n)
        {
            i++;
            p = p->next;
        }
        newNode->next = p->next;
        p->next->previous = newNode;
        p->next = newNode;
        newNode->previous = p;
        list->size++;
    }
}

//We consider 1st element in the list to be on position 0. So if n=0 we remove the head.
//If we try to remove an element from a negative position return error mesage aloang with NULL value.
//If we remove an element from a position greater than the number of elements we remove the last elemnt in list.

node_cdll* remove_node_circular_doubly_linked_list(circular_doubly_linked_list* list, int n)
{
    node_cdll* p = list->head;

    if (p == NULL || list == NULL)
    {
        printf("\nWarning: The list is empty.\nAn element cannot be removed from an empty list.\n");
        return NULL;
    }

    if (n < 0)
    {
        printf("\nAn element cannot be removed from a negative position.\n");
        return NULL;
    }

    else if (p->next == list->head)
    {
        list->head = NULL;
        list->size--;
        return p;
    }

    else if (n == 0)
    {
        p->next->previous = p->previous;
        p->previous->next = p->next;
        list->head = list->head->next;
        list->size--;
        return p;
    }

    else
    {
        int i = 1;
        while (p->next != list->head && i <= n)
        {
            i++;
            p = p->next;
        }
        node_cdll* temp = p;
        p->previous->next = p->next;
        p->next->previous = p->previous;
        list->size--;
        return temp;
    }
}

void free_circular_doubly_linked_list(circular_doubly_linked_list* list)
{
    if (list != NULL)
    {
        node_cdll* curent = list->head;
        if (curent == NULL) {}

        else
        {
            while (curent->next != list->head)
            {
                node_cdll* aux = curent;

                curent = curent->next;
                free(aux);
                aux = NULL;
            }
        }
    }
    
    init_circular_doubly_linked_list(list);
}



void print_circular_doubly_linked_list(circular_doubly_linked_list* list)
{
    if (list->head == NULL || list->size <= 0 || list == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        node_cdll* p = list->head;
        printf("\nList contains the following elements: ");
        while (p->next != list->head)
        {
            printf("%s, ", p->name);
            p = p->next;

        }
        printf("%s.", p->name);
    }

}