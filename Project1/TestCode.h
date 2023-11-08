#pragma once

/*
*****Test Binary Tree /  Binary Search Tree******
tree_list* new_tree = BT_create_tree_list_transversal();
 BT_delete_tree_node(new_tree, "C");

//bst_queue_list* list1 = malloc(sizeof(bst_queue_list));
//bst_init_queue_list(list1);

//bst_insert(new_tree, "XXX");
bst_transversal_order(new_tree);
printf("\n");
tree_preorder(new_tree);
printf("\n");
tree_inorder(new_tree);
printf("\n");
tree_postorder(new_tree);
printf("\n");


printf("\nThe tree has %d nodes.", new_tree->nr_nodes);
printf("\nThe tree has height of %d.", bst_find_height(new_tree));

printf("\nMin valuie from tree is %s. ",bst_return_min_value(new_tree));
printf("\nMax valuie from tree is %s. ", bst_return_max_value(new_tree));

printf("\nMin valuie from tree is %s. ", BT_return_min_value(new_tree));
printf("\nMax valuie from tree is %s. ", BT_return_max_value(new_tree));


printf("\nroot>> %s", new_tree->root->name);
printf("\nroot->left>> %s", new_tree->root->left->name);
printf("\nroot->right>> %s", new_tree->root->right->name);
printf("\nroot->left->left>> %s", new_tree->root->left->left->name);
printf("\nroot->left->right>> %s", new_tree->root->left->right->name);
printf("\nroot->right-left>> %s", new_tree->root->right->left->name);
printf("\nroot->right->right>> %s", new_tree->root->right->right->name);

BT_search(new_tree, "X");

if(is_BT_BST(new_tree))
printf("\nThe Tree list is a BST.");
else
printf("\nThe Tree list is NOT a BST.");


bst_free(new_tree);
new_tree = NULL;


**********Test Circular Doubly Link List***************
   /* circular_doubly_linked_list* lista1 = malloc(sizeof(circular_doubly_linked_list));
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
         ***********Test Circular Linked List*****************

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
