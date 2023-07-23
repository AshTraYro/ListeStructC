#include "DoublyLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void init_doubly_linked_list(doubly_linked_list* list)
{
    list->size = 0;
    list->head = malloc(sizeof(node_dll));
    list->head = NULL;

}

unsigned int size_doubly_linked_list(doubly_linked_list* list)
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

doubly_linked_list* create_doubly_linked_list()
{
    int list_size;
    char a[10];
    printf("\nHow many items do you wish to have in your list? :: ");
    //scanf("%d",&list_size);
    fgets(a, sizeof a, stdin);
    list_size = atoi(a);

    doubly_linked_list* list = malloc(sizeof(doubly_linked_list));
    list->head = NULL;
    list->size = list_size;

    node_dll* p = NULL;

    for (int i = 0; i < list->size; i++)
    {
        node_dll* temp = malloc(sizeof(node_dll));
        temp->next = NULL;
        temp->previous = NULL;
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
            p = temp;
        }
    }

    return list;
}

//We consider 1st element in the list to be on position 0. So if n=0 we add in 1st position in the list, replace the head.
//If we try to add an element to a negative position return error mesage aloang with NULL value.
//If we add an element to a position greater than the number of elements we add the elemnt last in list.
void add_nth_elem_doubly_linked_list(doubly_linked_list* list, int n, char new_name[])
{
    node_dll* newNode;
    while (1) {
        newNode = malloc(sizeof(node_dll));
        if (newNode != NULL) {
            break;
        }
    }
    newNode->next = NULL;
    newNode->previous = NULL;
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
        newNode->next = list->head;
        list->head->previous = newNode;
        list->head = newNode;
        list->size++;
    }

    else
    {
        node_dll* p = list->head;
        int i = 1;

        while (p->next != NULL && i < n)
        {
            i++;
            p = p->next;
        }
        if(p->next != NULL)
        p->next->previous = newNode;
        newNode->next = p->next;
        p->next = newNode;
        newNode->previous = p;
        list->size++;
    }
}

//We consider 1st element in the list to be on position 0. So if n=0 we remove the head.
//If we try to remove an element from a negative position return error mesage aloang with NULL value.
//If we remove an element from a position greater than the number of elements we remove the last elemnt in list.
node_dll* remove_node_doubly_linked_list(doubly_linked_list* list, int n)
{
    node_dll* p = list->head;

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

    else if (p->next == NULL)
    {
        list->head = NULL;
        list->size--;
        return p;
    }

    else if (n == 0)
    {
        list->head = list->head->next;
        list->head->previous = NULL;
        list->size--;
        return p;
    }

    else
    {
        int i = 1;
        while (p->next->next != NULL && i < n)
        {
            i++;
            p = p->next;
        }
        node_dll* temp = p->next;
        if (p->next->next != NULL)
        {
            p->next->next->previous = p;
        }
        p->next = p->next->next;
        list->size--;
        return temp;
    }
}

void free_doubly_linked_list(doubly_linked_list* list)
{
    if (list != NULL)
    {
        node_dll* curent = list->head;
        while (curent != NULL)
        {
            node_dll* aux = curent;

            curent = curent->next;
            free(aux);
            aux = NULL;
        }
    }
    
    init_doubly_linked_list(list);
}



void print_doubly_linked_list(doubly_linked_list* list)
{
    if (list->head == NULL || list->size <= 0 || list == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        node_dll* p = list->head;
        printf("\nList contains the following elements: ");
        while (p->next != NULL)
        {
            printf("%s, ", p->name);
            p = p->next;

        }
        printf("%s.", p->name);
    }

}