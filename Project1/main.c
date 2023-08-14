#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>

#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "CircularDoublyLinkedList.h"
#include "StackList.h"


int main()
{/*
    circular_doubly_linked_list* lista1 = malloc(sizeof(circular_doubly_linked_list));
    init_circular_doubly_linked_list(lista1);
    free_circular_doubly_linked_list(lista1);
    lista1 = create_circular_doubly_linked_list();
    print_circular_doubly_linked_list(lista1);
    node* p = lista1->head;

    do
    {
        printf("\nAdresa elementului este: %p", &p);
        printf("\nAdresa stocata in element este: %p", p);
        printf("\nAdresa stocata in element->next este: %p", p->next);
        printf("\nAdresa stocata in element->previous este: %p\n", p->previous);
        p = p->next;
    } while (p != lista1->head);

    add_nth_elem_circular_doubly_linked_list(lista1, 3, "NOU");
    print_circular_doubly_linked_list(lista1);
    node* q = lista1->head;

    do
    {
        printf("\nAdresa elementului este: %p", &q);
        printf("\nAdresa stocata in element este: %p", q);
        printf("\nAdresa stocata in element->next este: %p", q->next);
        printf("\nAdresa stocata in element->previous este: %p\n", q->previous);
        q = q->next;
    } while (q != lista1->head);

    node* rem = remove_node_circular_doubly_linked_list(lista1, 2);
    printf("\nAdresa elementului scos este: %p", &rem);
    printf("\nAdresa stocata in element scos este: %p", rem);
    printf("\nAdresa stocata in element->next scos este: %p", rem->next);
    printf("\nAdresa stocata in element->previous este: %p\n", rem->previous);

    print_circular_doubly_linked_list(lista1);
    node* r = lista1->head;
    do
    {
        printf("\nAdresa elementului este: %p", &r);
        printf("\nAdresa stocata in element este: %p", r);
        printf("\nAdresa stocata in element->next este: %p", r->next);
        printf("\nAdresa stocata in element->previous este: %p\n", r->previous);
        r = r->next;
    } while (r != lista1->head);

    free_circular_doubly_linked_list(lista1);
    free(lista1);
    lista1 = NULL;
    */

    /*
    circular_linked_list* lista1 = malloc(sizeof(circular_linked_list));
    init_circular_linked_list(lista1);
    free_circular_linked_list(lista1);
    lista1 = create_circular_linked_list();
    print_circular_linked_list(lista1);
    node* p = lista1->head;
   do
    {
        printf("\nAdresa elementului este: %p", &p);
        printf("\nAdresa stocata in element este: %p", p);
        printf("\nAdresa stocata in element->next este: %p", p->next);
        //printf("\nAdresa stocata in element->previous este: %p\n", p->previous);
        p = p->next;
   } while (p != lista1->head);

    add_nth_elem_circular_linked_list(lista1, 3, "NOU"); 
    print_circular_linked_list(lista1);
    node* q = lista1->head;

    do
    {
        printf("\nAdresa elementului este: %p", &q);
        printf("\nAdresa stocata in element este: %p", q);
        printf("\nAdresa stocata in element->next este: %p", q->next);
        //printf("\nAdresa stocata in element->previous este: %p\n", q->previous);
        q = q->next;
    } while (q != lista1->head);

    node *rem = remove_node_circular_linked_list(lista1, 2);
        printf("\nAdresa elementului scos este: %p", &rem);
        printf("\nAdresa stocata in element scos este: %p", rem);
        printf("\nAdresa stocata in element->next scos este: %p", rem->next);
        //printf("\nAdresa stocata in element->previous este: %p\n", rem->previous);

    print_circular_linked_list(lista1);
    node* r = lista1->head;
    do
    {
        printf("\nAdresa elementului este: %p", &r);
        printf("\nAdresa stocata in element este: %p", r);
        printf("\nAdresa stocata in element->next este: %p", r->next);
        //printf("\nAdresa stocata in element->previous este: %p\n", r->previous);
        r = r->next;
    } while (r != lista1->head);

    free_circular_linked_list(lista1);
    free(lista1);
    lista1 = NULL;*/


    
    linked_list* list_type_linked_list = malloc(sizeof(linked_list));
    init_linked_list(list_type_linked_list);
    doubly_linked_list* list_type_doubly_linked_list = malloc(sizeof(doubly_linked_list));
    init_doubly_linked_list(list_type_doubly_linked_list);
    circular_linked_list* list_type_circular_linked_list = malloc(sizeof(circular_linked_list));
    init_circular_linked_list(list_type_circular_linked_list);
    circular_doubly_linked_list* list_type_circular_doubly_linked_list = malloc(sizeof(circular_doubly_linked_list));
    init_circular_doubly_linked_list(list_type_circular_doubly_linked_list);
    stack_list* list_type_stack_list = malloc(sizeof(stack_list));
    init_stack_list(list_type_stack_list);

    mainmenu:
    while(1)
    {
        printf("\n\nYOU CAN DO MORE OPERATIONS WITH THE FOLLOWING TYPES OF LISTS:"
            "\n\t<<IF YOU WANT TO HAVE FUN WITH LINKED LIST - type: LL>>"
            "\n\t<<IF YOU WANT TO HAVE FUN WITH DOUBLY LINKED LIST - type: DLL>>"
            "\n\t<<IF YOU WANT TO HAVE FUN WITH CIRCULAR LINKED LIST - type: CLL>>"
            "\n\t<<IF YOU WANT TO HAVE FUN WITH CIRCULAR DOUBLY LINKED LIST - type: CDLL>>"
            "\n\t<<IF YOU WANT TO HAVE FUN WITH STACK LIST - type: SL>>"
            "\n\t<<IF YOU WANT TO QUIT - type: Quit>>"
            "\n\t<<<<WHAT DO YOU WISH TO DO NEXT? >>>> ");
        char command[64];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "Quit") == 0)
        {
            goto Quit_Program;
        }

        if (strcmp(command, "LL") == 0)
        {
            goto Linked_List;
        }

        if (strcmp(command, "DLL") == 0)
        {
            goto Doubly_Linked_List;
        }

        if (strcmp(command, "CLL") == 0)
        {
            goto Circular_Linked_List;
        }

        if (strcmp(command, "CDLL") == 0)
        {
            goto Circular_Doubly_Linked_List;
        }

        if (strcmp(command, "SL") == 0)
        {
            goto Stack_List;
        }
    }

    Linked_List:
    while (1)
    {
        printf("\n\nYOU CAN DO THE FOLLOWING OPERATIONS WITH THE SIMPLE LINKED LIST:"
            "\n\t<<CREATE THE LIST - type: Create>>"
            "\n\t<<ADD A NEW NODE ON THE DESIRED POSITION (FIRST ELEMENT FROM THE LIST IS 0 AND THE LAS ONE IS N-1 (N = NUMBER OF ELEMENTS) - type: AddNode>>"
            "\n\t<<REMOVE A NODE FROM THE DESIRED POSITION (FIRST ELEMENT FROM THE LIST IS 0 AND THE LAS ONE IS N-1 (N = NUMBER OF ELEMENTS) - type: RemoveNode>>"
            "\n\t<<SHOW THE CONTENT OF THE LIST - type: Print>>"
            "\n\t<<SHOW DIMENSION (NUMBER OF ELEMENTS) OF THE LIST - type: Dimension"
            "\n\t<<EMPTY THE LIST (WILL RESULT A INITIALIZED LIST - type: Delete>>"
            "\n\t<<IF YOU WANT TO GO BACK TO MAIN MENU WITH LISTS - type: MainMenu>>"
            "\n\t<<IF YOU WANT TO QUIT - type: Quit>>"
            "\n\t<<<<WHAT DO YOU WISH TO DO WITH THE LIST? >>>> ");
        char command[64];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "Quit") == 0)
        {
            goto Quit_Program;
        }

        if (strcmp(command, "MainMenu") == 0)
        {
            free_linked_list(list_type_linked_list);
            free(list_type_linked_list);
            list_type_linked_list = NULL;
            goto mainmenu;
        }

        if (strcmp(command, "Create") == 0)
        {
            free_linked_list(list_type_linked_list);
            free(list_type_linked_list);
            list_type_linked_list = NULL;
            list_type_linked_list = create_linked_list();
        }

        if (strcmp(command, "Print") == 0)
        {
            print_linked_list(list_type_linked_list);
        }

        if (strcmp(command, "AddNode") == 0)
        {
            int poz;
            char nume[32];
            printf("\nENTER THE POSITION FOR THE NEW PERSON FROM THE LIST: ");
            //scanf("%d", &poz);
            char a[10];
            fgets(a, sizeof a, stdin);
            poz = atoi(a);
            printf("\nENTER THE NAME FOR THE NEW PERSON FROM THE LIST: ");
            //scanf("%d", &varsta);
            fgets(nume, sizeof nume, stdin);
            nume[strcspn(nume, "\n")] = 0;
            add_nth_elem_linked_list(list_type_linked_list, poz, nume);
            if (poz >= 0)
            printf("\nPERSON WITH THE NAME %s HAS BEEN ADDED TO THE LIST\n", nume);
        }

        if (strcmp(command, "RemoveNode") == 0)
        {
            int poz;
            printf("\nENTER THE POSITION FOR THE PERSON YOU WANT TO REMOVE FROM THE LIST: ");
            //scanf("%d", &poz);
            char a[10];
            fgets(a, sizeof a, stdin);
            poz = atoi(a);
            node_ll* removed = remove_node_linked_list(list_type_linked_list, poz);
            if (removed)
            printf("\nPERSON WITH THE NAME %s HAS BEEN REMOVED FROM THE LIST\n", removed->name);
            free(removed);
            removed = NULL;
        }

        if (strcmp(command, "Dimension") == 0)
        {
            printf("\nNUMBER OF THE PERSON FROM THE LIST IS: %d", size_linked_list(list_type_linked_list));
        }

        if (strcmp(command, "Delete") == 0)
        {
            free_linked_list(list_type_linked_list);
        }
    }

Doubly_Linked_List:
    while (1)
    {
        printf("\n\nYOU CAN DO THE FOLLOWING OPERATIONS WITH THE DOUBLY LINKED LIST:"
            "\n\t<<CREATE THE LIST - type: Create>>"
            "\n\t<<ADD A NEW NODE ON THE DESIRED POSITION (FIRST ELEMENT FROM THE LIST IS 0 AND THE LAS ONE IS N-1 (N = NUMBER OF ELEMENTS) - type: AddNode>>"
            "\n\t<<REMOVE A NODE FROM THE DESIRED POSITION (FIRST ELEMENT FROM THE LIST IS 0 AND THE LAS ONE IS N-1 (N = NUMBER OF ELEMENTS) - type: RemoveNode>>"
            "\n\t<<SHOW THE CONTENT OF THE LIST - type: Print>>"
            "\n\t<<SHOW DIMENSION (NUMBER OF ELEMENTS) OF THE LIST - type: Dimension"
            "\n\t<<EMPTY THE LIST (WILL RESULT A INITIALIZED LIST - type: Delete>>"
            "\n\t<<IF YOU WANT TO GO BACK TO MAIN MENU WITH LISTS - type: MainMenu>>"
            "\n\t<<IF YOU WANT TO QUIT - type: Quit>>"
            "\n\t<<<<WHAT DO YOU WISH TO DO WITH THE LIST? >>>> ");
        char command[64];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "Quit") == 0)
        {
            goto Quit_Program;
        }

        if (strcmp(command, "MainMenu") == 0)
        {
            free_doubly_linked_list(list_type_doubly_linked_list);
            free(list_type_doubly_linked_list);
            list_type_doubly_linked_list = NULL;
            goto mainmenu;
        }

        if (strcmp(command, "Create") == 0)
        {
            free_doubly_linked_list(list_type_doubly_linked_list);
            free(list_type_doubly_linked_list);
            list_type_doubly_linked_list = NULL;
            list_type_doubly_linked_list = create_doubly_linked_list();
        }

        if (strcmp(command, "Print") == 0)
        {
            print_doubly_linked_list(list_type_doubly_linked_list);
        }

        if (strcmp(command, "AddNode") == 0)
        {
            int poz;
            char nume[32];
            printf("\nENTER THE POSITION FOR THE NEW PERSON FROM THE LIST: ");
            //scanf("%d", &poz);
            char a[10];
            fgets(a, sizeof a, stdin);
            poz = atoi(a);
            printf("\nENTER THE NAME FOR THE NEW PERSON FROM THE LIST: ");
            //scanf("%d", &varsta);
            fgets(nume, sizeof nume, stdin);
            nume[strcspn(nume, "\n")] = 0;
            add_nth_elem_doubly_linked_list(list_type_doubly_linked_list, poz, nume);
            if (poz >= 0)
            printf("\nPERSON WITH THE NAME %s HAS BEEN ADDED TO THE LIST\n", nume);
        }

        if (strcmp(command, "RemoveNode") == 0)
        {
            int poz;
            printf("\nENTER THE POSITION FOR THE PERSON YOU WANT TO REMOVE FROM THE LIST: ");
            //scanf("%d", &poz);
            char a[10];
            fgets(a, sizeof a, stdin);
            poz = atoi(a);
            node_dll* removed = remove_node_doubly_linked_list(list_type_doubly_linked_list, poz);
            if (removed)
            printf("\nPERSON WITH THE NAME %s HAS BEEN REMOVED FROM THE LIST\n", removed->name);
            free(removed);
            removed = NULL;
        }

        if (strcmp(command, "Dimension") == 0)
        {
            printf("\nNUMBER OF THE PERSON FROM THE LIST IS: %d", size_doubly_linked_list(list_type_doubly_linked_list));
        }

        if (strcmp(command, "Delete") == 0)
        {
            free_doubly_linked_list(list_type_doubly_linked_list);
        }
    }

Circular_Linked_List:
    while (1)
    {
        printf("\n\nYOU CAN DO THE FOLLOWING OPERATIONS WITH THE CIRCULAR LINKED LIST:"
            "\n\t<<CREATE THE LIST - type: Create>>"
            "\n\t<<ADD A NEW NODE ON THE DESIRED POSITION (FIRST ELEMENT FROM THE LIST IS 0 AND THE LAS ONE IS N-1 (N = NUMBER OF ELEMENTS) - type: AddNode>>"
            "\n\t<<REMOVE A NODE FROM THE DESIRED POSITION (FIRST ELEMENT FROM THE LIST IS 0 AND THE LAS ONE IS N-1 (N = NUMBER OF ELEMENTS) - type: RemoveNode>>"
            "\n\t<<SHOW THE CONTENT OF THE LIST - type: Print>>"
            "\n\t<<SHOW DIMENSION (NUMBER OF ELEMENTS) OF THE LIST - type: Dimension"
            "\n\t<<EMPTY THE LIST (WILL RESULT A INITIALIZED LIST - type: Delete>>"
            "\n\t<<IF YOU WANT TO GO BACK TO MAIN MENU WITH LISTS - type: MainMenu>>"
            "\n\t<<IF YOU WANT TO QUIT - type: Quit>>"
            "\n\t<<<<WHAT DO YOU WISH TO DO WITH THE LIST? >>>> ");
        char command[64];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "Quit") == 0)
        {
            goto Quit_Program;
        }

        if (strcmp(command, "MainMenu") == 0)
        {
            free_circular_linked_list(list_type_circular_linked_list);
            free(list_type_circular_linked_list);
            list_type_circular_linked_list = NULL;
            goto mainmenu;
        }

        if (strcmp(command, "Create") == 0)
        {
            free_circular_linked_list(list_type_circular_linked_list);
            free(list_type_circular_linked_list);
            list_type_circular_linked_list = NULL;
            list_type_circular_linked_list = create_circular_linked_list();
        }

        if (strcmp(command, "Print") == 0)
        {
            print_circular_linked_list(list_type_circular_linked_list);
        }

        if (strcmp(command, "AddNode") == 0)
        {
            int poz;
            char nume[32];
            printf("\nENTER THE POSITION FOR THE NEW PERSON FROM THE LIST: ");
            //scanf("%d", &poz);
            char a[10];
            fgets(a, sizeof a, stdin);
            poz = atoi(a);
            printf("\nENTER THE NAME FOR THE NEW PERSON FROM THE LIST: ");
            //scanf("%d", &varsta);
            fgets(nume, sizeof nume, stdin);
            nume[strcspn(nume, "\n")] = 0;
            add_nth_elem_circular_linked_list(list_type_circular_linked_list, poz, nume);
            if (poz >= 0)
            printf("\nPERSON WITH THE NAME %s HAS BEEN ADDED TO THE LIST\n", nume);
        }

        if (strcmp(command, "RemoveNode") == 0)
        {
            int poz;
            printf("\nENTER THE POSITION FOR THE PERSON YOU WANT TO REMOVE FROM THE LIST: ");
            //scanf("%d", &poz);
            char a[10];
            fgets(a, sizeof a, stdin);
            poz = atoi(a);
            node_cll* removed = remove_node_circular_linked_list(list_type_circular_linked_list, poz);
            if (removed)
            printf("\nPERSON WITH THE NAME %s HAS BEEN REMOVED FROM THE LIST\n", removed->name);
            free(removed);
            removed = NULL;
        }

        if (strcmp(command, "Dimension") == 0)
        {
            printf("\nNUMBER OF THE PERSON FROM THE LIST IS: %d", size_circular_linked_list(list_type_circular_linked_list));
        }

        if (strcmp(command, "Delete") == 0)
        {
            free_circular_linked_list(list_type_circular_linked_list);
        }
    }

Circular_Doubly_Linked_List:
    while (1)
    {
        printf("\n\nYOU CAN DO THE FOLLOWING OPERATIONS WITH THE CIRCULAR DOUBLY LINKED LIST:"
            "\n\t<<CREATE THE LIST - type: Create>>"
            "\n\t<<ADD A NEW NODE ON THE DESIRED POSITION (FIRST ELEMENT FROM THE LIST IS 0 AND THE LAS ONE IS N-1 (N = NUMBER OF ELEMENTS) - type: AddNode>>"
            "\n\t<<REMOVE A NODE FROM THE DESIRED POSITION (FIRST ELEMENT FROM THE LIST IS 0 AND THE LAS ONE IS N-1 (N = NUMBER OF ELEMENTS) - type: RemoveNode>>"
            "\n\t<<SHOW THE CONTENT OF THE LIST - type: Print>>"
            "\n\t<<SHOW DIMENSION (NUMBER OF ELEMENTS) OF THE LIST - type: Dimension"
            "\n\t<<EMPTY THE LIST (WILL RESULT A INITIALIZED LIST - type: Delete>>"
            "\n\t<<IF YOU WANT TO GO BACK TO MAIN MENU WITH LISTS - type: MainMenu>>"
            "\n\t<<IF YOU WANT TO QUIT - type: Quit>>"
            "\n\t<<<<WHAT DO YOU WISH TO DO WITH THE LIST? >>>> ");
        char command[64];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "Quit") == 0)
        {
            goto Quit_Program;
        }

        if (strcmp(command, "MainMenu") == 0)
        {
            free_circular_doubly_linked_list(list_type_circular_doubly_linked_list);
            free(list_type_circular_doubly_linked_list);
            list_type_circular_doubly_linked_list = NULL;
            goto mainmenu;
        }

        if (strcmp(command, "Create") == 0)
        {
            free_circular_doubly_linked_list(list_type_circular_doubly_linked_list);
            free(list_type_circular_doubly_linked_list);
            list_type_circular_doubly_linked_list = NULL;
            list_type_circular_doubly_linked_list = create_circular_doubly_linked_list();
        }

        if (strcmp(command, "Print") == 0)
        {
            print_circular_doubly_linked_list(list_type_circular_doubly_linked_list);
        }

        if (strcmp(command, "AddNode") == 0)
        {
            int poz;
            char nume[32];
            printf("\nENTER THE POSITION FOR THE NEW PERSON FROM THE LIST: ");
            //scanf("%d", &poz);
            char a[10];
            fgets(a, sizeof a, stdin);
            poz = atoi(a);
            printf("\nENTER THE NAME FOR THE NEW PERSON FROM THE LIST: ");
            //scanf("%d", &varsta);
            fgets(nume, sizeof nume, stdin);
            nume[strcspn(nume, "\n")] = 0;
            add_nth_elem_circular_doubly_linked_list(list_type_circular_doubly_linked_list, poz, nume);
            if (poz >= 0)
            printf("\nPERSON WITH THE NAME %s HAS BEEN ADDED TO THE LIST\n", nume);
        }

        if (strcmp(command, "RemoveNode") == 0)
        {
            int poz;
            printf("\nENTER THE POSITION FOR THE PERSON YOU WANT TO REMOVE FROM THE LIST: ");
            //scanf("%d", &poz);
            char a[10];
            fgets(a, sizeof a, stdin);
            poz = atoi(a);
            node_cdll* removed = remove_node_circular_doubly_linked_list(list_type_circular_doubly_linked_list, poz);
            if (removed)
            printf("\nPERSON WITH THE NAME %s HAS BEEN REMOVED FROM THE LIST\n", removed->name);
            free(removed);
            removed = NULL;
        }

        if (strcmp(command, "Dimension") == 0)
        {
            printf("\nNUMBER OF THE PERSON FROM THE LIST IS: %d", size_circular_doubly_linked_list(list_type_circular_doubly_linked_list));
        }

        if (strcmp(command, "Delete") == 0)
        {
            free_circular_doubly_linked_list(list_type_circular_doubly_linked_list);
        }
    }

Stack_List:
    while (1)
    {
        printf("\n\nYOU CAN DO THE FOLLOWING OPERATIONS WITH THE STACK LIST:"
            "\n\t<<CREATE THE LIST - type: Create>>"
            "\n\t<<PUSH A NEW NODE INTO THE STACK - LAST ELEMENT INSERTED WILL BE THE HEAD OF THE LIST (1ST ELEMENT FROM LIST) - type: Push>>"
            "\n\t<POP A NODE FROM THE STACK - LAST ELEMENT INSERTED WILL BE THE HEAD OF THE LIST - WE REMOVE THE HEAD AND 2ND ELEMENT BECOME THE HEAD  - type: Pop>>"
            "\n\t<<SHOW THE CONTENT OF THE LIST - type: Print>>"
            "\n\t<<SHOW DIMENSION (NUMBER OF ELEMENTS) OF THE LIST - type: Dimension"
            "\n\t<<EMPTY THE LIST WILL RESULT A INITIALIZED LIST - type: Delete>>"
            "\n\t<<TO SEE THE 1ST ELEMENT FROM THE LIST - type: Peek>>"
            "\n\t<<IF YOU WANT TO GO BACK TO MAIN MENU WITH LISTS - type: MainMenu>>"
            "\n\t<<IF YOU WANT TO QUIT - type: Quit>>"
            "\n\t<<<<WHAT DO YOU WISH TO DO WITH THE LIST? >>>> ");
        char command[64];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "Quit") == 0)
        {
            goto Quit_Program;
        }

        if (strcmp(command, "MainMenu") == 0)
        {
            free_stack_list(list_type_stack_list);
            free(list_type_stack_list);
            list_type_stack_list = NULL;
            goto mainmenu;
        }

        if (strcmp(command, "Create") == 0)
        {
            free_stack_list(list_type_stack_list);
            free(list_type_stack_list);
            list_type_stack_list = NULL;
            list_type_stack_list = create_stack_list();
        }

        if (strcmp(command, "Print") == 0)
        {
            print_stack_list(list_type_stack_list);
        }

        if (strcmp(command, "Push") == 0)
        {
            char nume[32];
            printf("\nENTER THE NAME FOR THE NEW PERSON FROM THE LIST: ");
            //scanf("%d", &varsta);
            fgets(nume, sizeof nume, stdin);
            nume[strcspn(nume, "\n")] = 0;
            push_stack_list(list_type_stack_list, nume);
            printf("\nPERSON WITH THE NAME %s HAS BEEN ADDED TO THE LIST\n", nume);
        }

        if (strcmp(command, "Pop") == 0)
        {
            node_sl* removed = pop_stack_list(list_type_stack_list);
            if (removed)
            printf("\nPERSON WITH THE NAME %s HAS BEEN REMOVED FROM THE LIST\n", removed->name);
            free(removed);
            removed = NULL;
        }

        if (strcmp(command, "Dimension") == 0)
        {
            printf("\nNUMBER OF THE PERSON FROM THE LIST IS: %d", size_stack_list(list_type_stack_list));
        }

        if (strcmp(command, "Delete") == 0)
        {
            free_stack_list(list_type_stack_list);
        }

        if (strcmp(command, "Peek") == 0)
        {
            if (list_type_stack_list->head->name == NULL || list_type_stack_list == NULL)
            {
                printf("\nTHE LIST IS EMPTY.");
            }
            else
            {
                printf("\nThe 1ST PERSON IN THE LIST IS %s.", list_type_stack_list->head->name);
            }
        }
    }


Quit_Program:
    if (list_type_linked_list != NULL)
    {
        free_linked_list(list_type_linked_list);
        free(list_type_linked_list);
        list_type_linked_list = NULL;
    }
    
    if (list_type_doubly_linked_list != NULL)
    {
        free_doubly_linked_list(list_type_doubly_linked_list);
        free(list_type_doubly_linked_list);
        list_type_doubly_linked_list = NULL;
    }

    if (list_type_circular_linked_list != NULL)
    {
        free_circular_linked_list(list_type_circular_linked_list);
        free(list_type_circular_linked_list);
        list_type_circular_linked_list = NULL;
    }

    if (list_type_circular_doubly_linked_list != NULL)
    {
        free_circular_doubly_linked_list(list_type_circular_doubly_linked_list);
        free(list_type_circular_doubly_linked_list);
        list_type_circular_doubly_linked_list = NULL;
    }

    if (list_type_stack_list != NULL)
    {
        free_stack_list(list_type_stack_list);
        free(list_type_stack_list);
        list_type_stack_list = NULL;
    }
    
    _CrtDumpMemoryLeaks();
    return 0;
}

