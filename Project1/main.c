#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>

#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "CircularDoublyLinkedList.h"
#include "StackList.h"
#include "QueueList.h"
#include "BSTree.h"


int main()
{
    
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
    queue_list* list_type_queue_list = malloc(sizeof(queue_list));
    init_queue_list(list_type_queue_list);
    tree_list* new_tree = malloc(sizeof(tree_list));
    bst_init_tree_list(new_tree);

    mainmenu:
    while(1)
    {
        printf("\n\nYOU CAN DO DIFFERENT KIND OF OPERATIONS WITH THE FOLLOWING TYPES OF LISTS - CHOOSE A LIST:"
            "\n\t<<IF YOU WANT TO HAVE FUN WITH LINKED LIST - type: LL>>"
            "\n\t<<IF YOU WANT TO HAVE FUN WITH DOUBLY LINKED LIST - type: DLL>>"
            "\n\t<<IF YOU WANT TO HAVE FUN WITH CIRCULAR LINKED LIST - type: CLL>>"
            "\n\t<<IF YOU WANT TO HAVE FUN WITH CIRCULAR DOUBLY LINKED LIST - type: CDLL>>"
            "\n\t<<IF YOU WANT TO HAVE FUN WITH STACK LIST - type: SL>>"
            "\n\t<<IF YOU WANT TO HAVE FUN WITH STACK LIST - type: QL>>"
            "\n\t<<IF YOU WANT TO HAVE FUN WITH BINARY TREE - type: BT>>"
            "\n\t<<IF YOU WANT TO HAVE FUN WITH BINARY SEARCH TREE - type: BST>>"
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

        if (strcmp(command, "QL") == 0)
        {
            goto Queue_List;
        }

        if (strcmp(command, "BT") == 0)
        {
            goto BT_TREE;
        }

        if (strcmp(command, "BST") == 0)
        {
            goto BST_TREE;
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

Queue_List:
    while (1)
    {
        printf("\n\nYOU CAN DO THE FOLLOWING OPERATIONS WITH THE QUEUE LIST:"
            "\n\t<<CREATE THE LIST - type: Create>>"
            "\n\t<<EQUEUE A NEW NODE INTO THE QUEUE - LAST ELEMENT INSERTED WILL BE AT THE END OF THE LIST - type: Enqueue>>"
            "\n\t<<DEQUEUE A NODE FROM THE STACK - FIRST ELEMENT FROM THE LIST WILL BE REMOVED - SECOND ELEMENT FROM THE LIST BECOME THE FRONT  - type: Dequeue>>"
            "\n\t<<SHOW THE CONTENT OF THE LIST - type: Print>>"
            "\n\t<<SHOW DIMENSION (NUMBER OF ELEMENTS) OF THE LIST - type: Dimension>>"
            "\n\t<<EMPTY THE LIST WILL RESULT A INITIALIZED LIST - type: Delete>>"
            "\n\t<<TO SEE THE 1ST ELEMENT FROM THE LIST - type: Peek>>"
            "\n\t<<IF YOU WANT TO CHECK IF THE QUEUE LIST IS EMPTY - type: Empty>>"
            "\n\t<<IF YOU WANT TO CHECK IF THE QUEUE LIST IS FULL - type: Full>>"
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
            free_queue_list(list_type_queue_list);
            free(list_type_queue_list);
            list_type_queue_list = NULL;
            goto mainmenu;
        }

        if (strcmp(command, "Create") == 0)
        {
            free_queue_list(list_type_queue_list);
            free(list_type_queue_list);
            list_type_queue_list = NULL;
            list_type_queue_list = create_queue_list();
        }

        if (strcmp(command, "Print") == 0)
        {
            print_queue_list(list_type_queue_list);
        }

        if (strcmp(command, "Enqueue") == 0)
        {
            if (list_type_queue_list->size == list_type_queue_list->max_size)
            {
                printf("\nThe list is Full, you cannot add anymore items.");
            }

            else
            {
                char nume[32];
                printf("\nENTER THE NAME FOR THE NEW PERSON FROM THE LIST: ");
                //scanf("%d", &varsta);
                fgets(nume, sizeof nume, stdin);
                nume[strcspn(nume, "\n")] = 0;
                enqueue_queue_list(list_type_queue_list, nume);
                printf("\nPERSON WITH THE NAME %s HAS BEEN ADDED TO THE LIST\n", nume);
            }
        }

        if (strcmp(command, "Dequeue") == 0)
        {
            node_ql* removed = dequeue_queue_list(list_type_queue_list);
            if (removed)
                printf("\nPERSON WITH THE NAME %s HAS BEEN REMOVED FROM THE LIST\n", removed->name);
            free(removed);
            removed = NULL;
        }

        if (strcmp(command, "Dimension") == 0)
        {
            printf("\nNUMBER OF THE PERSON FROM THE LIST IS: %d", size_queue_list(list_type_queue_list));
        }

        if (strcmp(command, "Delete") == 0)
        {
            free_queue_list(list_type_queue_list);
        }

        if (strcmp(command, "Peek") == 0)
        {
            if (list_type_queue_list->front->name == NULL || list_type_stack_list == NULL)
            {
                printf("\nTHE LIST IS EMPTY.");
            }
            else
            {
                printf("\nThe 1ST PERSON IN THE LIST IS %s.", list_type_queue_list->front->name);
            }
        }

        if (strcmp(command, "Empty") == 0)
        {
            printf("Is %s that the list is empty.",is_queue_empty(list_type_queue_list) ? "true" : "false");
        }

        if (strcmp(command, "Full") == 0)
        {
            printf("Is %s that the list is full.",is_queue_full(list_type_queue_list) ? "true" : "false");
        }
    }

BT_TREE:
    while (1)
    {
        printf("\n\nYOU CAN DO THE FOLLOWING OPERATIONS WITH BINARY TREE:"
            "\n\t<<CREATE A BINARY TREE - type: Create>>"
            "\n\t<<INSERT A NEW NODE INTO BINARY TREE - ELEMENT WILL BE INSERTED AT THE FISRT AVAILABLE NULL NODE FROM UP TO BOTTOM AND LEFT TO RIGHT - type: Insert>>"
            "\n\t<<DELETE A NODE FROM BINARY TREE - NODE WILL BE DELETED AND REPLACED WITH THE PRIORITY TO THE RIGHT NODE IF IS NOT NULL  - type: Delete>>"
            "\n\t<<CHECK IF BINARY TREE IS A BINARY SEARCH TREE  - type: Check>>"
            "\n\t<<PRINT THE CONTENT OF BINARY TREE - in Transversal-Oreder(All leves from left to right) - type: Transversal>>"
            "\n\t<<PRINT THE CONTENT OF BINARY TREE - in Pre-Oreder(Data-Left-Right)  - type: Preorder>>"
            "\n\t<<PRINT THE CONTENT OF BINARY TREE - in In-Oreder(Left-Data-Right)  - type: Inorder>>"
            "\n\t<<PRINT THE CONTENT OF BINARY TREE - in Post-Oreder(Left-Right-Data)  - type: Postorder>>"
            "\n\t<<SEARCH FOR A VALUE IN THE BINARY TREE  - type: Search>>"
            "\n\t<<SHOW THE HEIGHT OF THE BINARY TREE  - type: Height>>"
            "\n\t<<SHOW DIMENSION (NUMBER OF NODES) OF THE BINARY TREE - type: Dimension>>"
            "\n\t<<DELETE THE BINARY TREE WILL RESULT A INITIALIZED TREE - type: Empty>>"
            "\n\t<<DISPLAY THE MINIMUM VALUE FROM THE BINARY TREE - type: Min>>"
            "\n\t<<DISPLAY THE MAXIMUM VALUE FROM THE BINARY TREE - type: Max>>"
            "\n\t<<IF YOU WANT TO GO BACK TO MAIN MENU WITH LISTS - type: MainMenu>>"
            "\n\t<<IF YOU WANT TO QUIT - type: Quit>>"
            "\n\t<<<<WHAT DO YOU WISH TO DO WITH BINARY TREE? >>>> ");
        char command[64];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "Quit") == 0)
        {
            goto Quit_Program;
        }

        if (strcmp(command, "MainMenu") == 0)
        {
            bst_free(new_tree);
            free(new_tree);
            new_tree = NULL;
            goto mainmenu;
        }

        if (strcmp(command, "Create") == 0)
        {
            bst_free(new_tree);
            free(new_tree);
            new_tree = NULL;
            new_tree = BT_create_tree_list_transversal();
        }

        if (strcmp(command, "Transversal") == 0)
        {
            bst_transversal_order(new_tree);
        }

        if (strcmp(command, "Preorder") == 0)
        {
            tree_preorder(new_tree);
        }

        if (strcmp(command, "Inorder") == 0)
        {
            tree_inorder(new_tree);
        }

        if (strcmp(command, "Postorder") == 0)
        {
            tree_postorder(new_tree);
        }

        if (strcmp(command, "Search") == 0)
        {
            char nume[32];
            printf("\nENTER THE NAME FOR THE PERSON YOU WANT TO SEARCH IN BINARY TREE: ");
            //scanf("%d", &varsta);
            fgets(nume, sizeof nume, stdin);
            nume[strcspn(nume, "\n")] = 0;
            BT_search(new_tree, nume);
        }

        if (strcmp(command, "Insert") == 0)
        {
            char nume[32];
            printf("\nENTER THE NAME FOR THE NEW PERSON IN BINARY TREE: ");
            //scanf("%d", &varsta);
            fgets(nume, sizeof nume, stdin);
            nume[strcspn(nume, "\n")] = 0;
            BT_insert_transversal(new_tree, nume);
            printf("\nPERSON WITH THE NAME %s HAS BEEN ADDED TO THE BINARY TREE TRANSVERSAL\n", nume);
            
        }

        if (strcmp(command, "Delete") == 0)
        {
            char nume[32];
            printf("\nENTER THE NAME FOR THE PERSON YOU WANT TO REMOVE FROM BINARY TREE: ");
            //scanf("%d", &varsta);
            fgets(nume, sizeof nume, stdin);
            nume[strcspn(nume, "\n")] = 0;
            BT_delete_tree_node(new_tree, nume);
            printf("\nPERSON WITH THE NAME %s HAS BEEN REMOVED FROM THE BINARY TREE\n", nume);
        }

        if (strcmp(command, "Dimension") == 0)
        {
            printf("\nNUMBER OF THE NODES FROM THE BINARY TREE IS: %d", new_tree->nr_nodes);
        }

        if (strcmp(command, "Empty") == 0)
        {
            bst_free(new_tree);
        }

        if (strcmp(command, "Min") == 0)
        {
            if (new_tree->root->name == NULL || new_tree == NULL)
            {
                printf("\nTHE BINARY TREE IS EMPTY.");
            }
            else
            {
                printf("\nTHE MINIMUM VALUE NAME IN THE BINARY TREE IS %s.", BT_return_min_value(new_tree));
            }
        }

        if (strcmp(command, "Max") == 0)
        {
            if (new_tree->root->name == NULL || new_tree == NULL)
            {
                printf("\nTHE BINARY TREE IS EMPTY.");
            }
            else
            {
                printf("\nTHE MAXIMUM VALUE NAME IN THE BINARY TREE IS %s.", BT_return_max_value(new_tree));
            }
        }
    }

BST_TREE:
    while (1)
    {
        printf("\n\nYOU CAN DO THE FOLLOWING OPERATIONS WITH BINARY SEARCH TREE:"
            "\n\t<<CREATE A BINARY SEARCH TREE - type: Create>>"
            "\n\t<<INSERT A NEW NODE INTO BINARY SEARCH TREE -  - type: Insert>>"
            "\n\t<<DELETE A NODE FROM BINARY SEARCH TREE - NODE WILL BE DELETED AND REPLACED WITH THE PRIORITY TO THE RIGHT NODE IF IS NOT NULL  - type: Delete>>"
            "\n\t<<PRINT THE CONTENT OF BINARY SEARCH TREE - in Transversal-Oreder(All leves from left to right) - type: Transversal>>"
            "\n\t<<PRINT THE CONTENT OF BINARY SEARCH TREE - in Pre-Oreder(Data-Left-Right)  - type: Preorder>>"
            "\n\t<<PRINT THE CONTENT OF BINARY SEARCH TREE - in In-Oreder(Left-Data-Right)  - type: Inorder>>"
            "\n\t<<PRINT THE CONTENT OF BINARY SEARCH TREE - in Post-Oreder(Left-Right-Data)  - type: Postorder>>"
            "\n\t<<SEARCH FOR A VALUE IN THE BINARY SEARCH TREE  - type: Search>>"
            "\n\t<<SHOW THE HEIGHT OF THE BINARY SEARCH TREE  - type: Height>>"
            "\n\t<<SHOW DIMENSION (NUMBER OF NODES) OF THE BINARY SEARCH TREE - type: Dimension>>"
            "\n\t<<DELETE THE BINARY TREE WILL RESULT A INITIALIZED TREE - type: Empty>>"
            "\n\t<<DISPLAY THE MINIMUM VALUE FROM THE BINARY SEARCH TREE - type: Min>>"
            "\n\t<<DISPLAY THE MAXIMUM VALUE FROM THE BINARY SEARCH TREE - type: Max>>"
            "\n\t<<IF YOU WANT TO GO BACK TO MAIN MENU WITH LISTS - type: MainMenu>>"
            "\n\t<<IF YOU WANT TO QUIT - type: Quit>>"
            "\n\t<<<<WHAT DO YOU WISH TO DO WITH BINARY TREE? >>>> ");
        char command[64];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "Quit") == 0)
        {
            goto Quit_Program;
        }

        if (strcmp(command, "MainMenu") == 0)
        {
            bst_free(new_tree);
            free(new_tree);
            new_tree = NULL;
            goto mainmenu;
        }

        if (strcmp(command, "Create") == 0)
        {
            bst_free(new_tree);
            free(new_tree);
            new_tree = NULL;
            new_tree = BST_create_tree_list();
        }

        if (strcmp(command, "Transversal") == 0)
        {
            bst_transversal_order(new_tree);
        }

        if (strcmp(command, "Preorder") == 0)
        {
            tree_preorder(new_tree);
        }

        if (strcmp(command, "Inorder") == 0)
        {
            tree_inorder(new_tree);
        }

        if (strcmp(command, "Postorder") == 0)
        {
            tree_postorder(new_tree);
        }

        if (strcmp(command, "Search") == 0)
        {
            char nume[32];
            printf("\nENTER THE NAME FOR THE PERSON YOU WANT TO SEARCH IN BINARY SEARCH TREE: ");
            //scanf("%d", &varsta);
            fgets(nume, sizeof nume, stdin);
            nume[strcspn(nume, "\n")] = 0;
            BST_search(new_tree, nume);
        }

        if (strcmp(command, "Insert") == 0)
        {
            char nume[32];
            printf("\nENTER THE NAME FOR THE NEW PERSON IN BINARY SEARCH TREE: ");
            //scanf("%d", &varsta);
            fgets(nume, sizeof nume, stdin);
            nume[strcspn(nume, "\n")] = 0;
            bst_insert(new_tree, nume);
            printf("\nPERSON WITH THE NAME %s HAS BEEN ADDED TO THE BINARY SEARCH TREE\n", nume);

        }

        if (strcmp(command, "Delete") == 0)
        {
            char nume[32];
            printf("\nENTER THE NAME FOR THE PERSON YOU WANT TO REMOVE FROM BINARY SEARCH TREE: ");
            //scanf("%d", &varsta);
            fgets(nume, sizeof nume, stdin);
            nume[strcspn(nume, "\n")] = 0;
            BST_delete_tree_node(new_tree, nume);
            printf("\nPERSON WITH THE NAME %s HAS BEEN REMOVED FROM THE BINARY TREE\n", nume);
        }

        if (strcmp(command, "Dimension") == 0)
        {
            printf("\nNUMBER OF THE NODES FROM THE BINARY TREE IS: %d", new_tree->nr_nodes);
        }

        if (strcmp(command, "Empty") == 0)
        {
            bst_free(new_tree);
        }

        if (strcmp(command, "Min") == 0)
        {
            if (new_tree->root->name == NULL || new_tree == NULL)
            {
                printf("\nTHE BINARY TREE IS EMPTY.");
            }
            else
            {
                printf("\nTHE MINIMUM VALUE NAME IN THE BINARY TREE IS %s.", bst_return_min_value(new_tree));
            }
        }

        if (strcmp(command, "Max") == 0)
        {
            if (new_tree->root->name == NULL || new_tree == NULL)
            {
                printf("\nTHE BINARY TREE IS EMPTY.");
            }
            else
            {
                printf("\nTHE MAXIMUM VALUE NAME IN THE BINARY TREE IS %s.", bst_return_max_value(new_tree));
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
    
    //_CrtDumpMemoryLeaks();
    return 0;
}

