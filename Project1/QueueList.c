#include "QueueList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

void init_queue_list(queue_list* list)
{
    list->size = 0;
    list->max_size = 10;
    list->front = malloc(sizeof(node_ql));
    list->front = NULL;
    list->rear = malloc(sizeof(node_ql));
    list->rear = NULL;

}

unsigned int size_queue_list(queue_list* list)
{
    if (list->front == NULL || list->size <= 0)
    {
        printf("\nList is empty");
        return 0;
    }
    else
    {
        return list->size;
    }
}

_Bool is_queue_empty(queue_list* list)
{
    if (list->size == 0)
        return true;
    else
        return false;
}

_Bool is_queue_full(queue_list* list)
{
    if (list->size == list->max_size)
        return true;
    else
        return false;
}

char* top_elem_queue(queue_list* list)
{
    return list->front->name;
}

queue_list* create_queue_list()
{
    queue_list* list = malloc(sizeof(queue_list));
    init_queue_list(list);

    int list_size;
    char a[10];
    printf("\nHow many items do you wish to have in your list? be carefull no more than %d :: ",list->max_size);
    //scanf("%d",&list_size);
    fgets(a, sizeof a, stdin);
    list_size = atoi(a);
    if (list_size > list->max_size)
    {
        printf("\nYou entered a value greater than the maximum accepted items in the list so you will be limited to %d.", list-> max_size);
        list_size = list->max_size;
    }
    list->size = list_size;

    for (int i = 0; i < list->size; i++)
    {
        node_ql* temp = malloc(sizeof(node_ql));
        temp->next = NULL;
        printf("\nType in the name for the person number %d from the list: ", i + 1);

        fgets(temp->name, sizeof temp->name, stdin);
        temp->name[strcspn(temp->name, "\n")] = 0;

        if (list->front == NULL)
        {
            list->front = temp;
            list->rear = temp;
        }
        else
        {
            list->rear->next = temp;
            list->rear = temp;
        }
    }

    return list;
}

//We consider last inserted element(Enqueue) in the list to be the last one in the linked list.
//So if we Enqueue an element, we will add it to the back of the list using rear pointer. - O(1)
void enqueue_queue_list(queue_list* list, char new_name[])
{
    if (list->size == list->max_size)
    {
        printf("\nThe list is Full, you cannot add anymore items.");
        return;
    }
    else
    {
        node_ql* newNode;
        while (1) {
            newNode = malloc(sizeof(node_ql));
            if (newNode != NULL) {
                break;
            }
        }
        newNode->next = NULL;
        strcpy_s(newNode->name, sizeof newNode->name, new_name);


        if (list->front == NULL)
        {
            list->front = newNode;
            list->rear = newNode;
            list->size++;

        }

        else
        {
            list->rear->next = newNode;
            list->rear = newNode;
            list->size++;
        }
    }
}

//We consider first inserted element in the list to be on position 0 (first element in the list - front.
//If we Dequeue an element we will remove the first element from the list and make the front to point to the next element in the list.
//If the list is empty we wil receive an error
node_ql* dequeue_queue_list(queue_list* list)
{
    node_ql* p = list->front;

    if (p == NULL || list == NULL)
    {
        printf("\nWarning: The list is empty.\nAn element cannot be removed from an empty list.\n");
        return NULL;
    }

    else if (p->next == NULL)
    {
        list->front = NULL;
        list->rear = NULL;
        list->size--;
        return p;
    }

    else
    {
        list->front = list->front->next;
        list->size--;
        return p;
    }
}

void free_queue_list(queue_list* list)
{
    if (list != NULL)
    {
        node_ql* curent = list->front;
        while (curent != NULL)
        {
            node_ql* aux = curent;

            curent = curent->next;
            free(aux);
            aux = NULL;
        }
    }

    init_queue_list(list);
}



void print_queue_list(queue_list* list)
{
    if (list->front == NULL || list->size <= 0 || list == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        node_ql* p = list->front;
        printf("\nList contains the following elements: ");
        while (p->next != NULL)
        {
            printf("%s, ", p->name);
            p = p->next;

        }
        printf("%s.", p->name);
    }

}