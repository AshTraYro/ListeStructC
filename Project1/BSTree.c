#include "BSTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>


void bst_init_tree_list(tree_list* list)
{
    list->root = NULL;
    list->nr_nodes = 0;
    list->tree_depth = -1;
    list->tree_height = -1;
}


node_tree* get_new_node_tree(char new_name[])
{
    node_tree* newNode;
    while (1) {
        newNode = malloc(sizeof(node_tree));
        if (newNode != NULL) {
            break;
        }
    }
    newNode->left = NULL;
    newNode->right = NULL;
    strcpy_s(newNode->name, sizeof newNode->name, new_name);

    return newNode;
}

node_tree* insert_tree_node(node_tree* root, char new_name[])
{
    if (root == NULL)
    {
        root = get_new_node_tree(new_name);
    }
    else if (strcmp(root->name, new_name) > 0 || strcmp(root->name, new_name) == 0)
    {
        root->left = insert_tree_node(root->left, new_name);
    }
    else
    {
        root->right = insert_tree_node(root->right, new_name);
    }

    return root;
}

void bst_insert(tree_list* tree, char new_name[])
{
    tree->root = insert_tree_node(tree->root, new_name);
    tree->tree_height = bst_find_height(tree);
    tree->nr_nodes++;
}

tree_list* BST_create_tree_list()
{
    tree_list* tree = malloc(sizeof(tree_list));
    bst_init_tree_list(tree);

    int nr_of_nodes = 0;
    char a[10];
    printf("\nHow many nodes do you wish to have in your tree?\n");
    //scanf("%d",&list_size);
    fgets(a, sizeof a, stdin);
    nr_of_nodes = atoi(a);

    for (int i = 0; i < nr_of_nodes; i++)
    {
        char name[32];
        printf("\nType in the name for the person on node number %d from the tree: ", i + 1);

        fgets(name, sizeof name, stdin);
        name[strcspn(name, "\n")] = 0;
        bst_insert(tree, name);
    }

    return tree;
}

node_tree* delete_tree_node(node_tree* root, char delete_name[])
{
    if (root == NULL)
        return NULL;
    else if (strcmp(root->name, delete_name) > 0)
        root->left = delete_tree_node(root->left, delete_name);
    else if (strcmp(root->name, delete_name) < 0)
        root->right = delete_tree_node(root->right, delete_name);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }

        else if (root->left == NULL)
        {
            node_tree* temp = root;
            root = root->right;
            free(temp);
            temp = NULL;
        }

        else if (root->right == NULL)
        {
            node_tree* temp = root;
            root = root->left;
            free(temp);
            temp = NULL;
        }

        else
        {
            strcpy_s(root->name, sizeof root->name, root->right->name);
            root->right = delete_tree_node(root->right, root->right->name);
        }
    }
    return root;
}

void BST_delete_tree_node(tree_list* tree, char delete_name[])
{
    tree->root = delete_tree_node(tree->root, delete_name);
    tree->tree_height = bst_find_height(tree);
    tree->nr_nodes--;
}

void search_node_BST(node_tree* root, char key[])
{
    if (root == NULL)
    {
        printf("\nThe value %s is not in the list\n", key);
    }
    else if (strcmp(root->name, key) == 0)
    {
        printf("\nThe value %s is in the list\n", key);
    }
    else if (strcmp(root->name, key) > 0)
    {
        search_node_BST(root->left, key);
    }
    else
    {
        search_node_BST(root->right, key);
    }
}

void BST_search(tree_list* tree, char key[])
{
    search_node_BST(tree->root, key);
}

node_tree* insert_tree_node_transversal(node_tree* root, char new_name[])
{
    if (root == NULL)
    {
        root = get_new_node_tree(new_name);
        return root;
    }

    bst_queue_list* list = create_bst_queue_list();
    bst_enqueue_queue_list(list, root);

    while (list->front != NULL)
    {
        node_tree* temp = bst_top_elem_queue_list(list);
        bst_dequeue_queue_list(list);

        if (temp->left != NULL)
            bst_enqueue_queue_list(list,temp->left);
        else
        {
            temp->left = get_new_node_tree(new_name);
            break;
        }
          
        if (temp->right != NULL)
            bst_enqueue_queue_list(list, temp->right);
        else
        {
            temp->right = get_new_node_tree(new_name);
            break;
        }
    }
    return root;
}

void BT_insert_transversal(tree_list* tree, char new_name[])
{
    tree->root = insert_tree_node_transversal(tree->root, new_name);
    tree->tree_height = bst_find_height(tree);
    tree->nr_nodes++;
}

tree_list* BT_create_tree_list_transversal()
{
    tree_list* tree = malloc(sizeof(tree_list));
    bst_init_tree_list(tree);

    int nr_of_nodes = 0;
    char a[10];
    printf("\nHow many nodes do you wish to have in your tree?\n");
    //scanf("%d",&list_size);
    fgets(a, sizeof a, stdin);
    nr_of_nodes = atoi(a);

    for (int i = 0; i < nr_of_nodes; i++)
    {
        char name[32];
        printf("\nType in the name for the person on node number %d from the tree: ", i + 1);

        fgets(name, sizeof name, stdin);
        name[strcspn(name, "\n")] = 0;
        BT_insert_transversal(tree, name);
    }

    return tree;
}



node_tree* delete_simple_tree_node(node_tree* root, char delete_name[])
{
    if (root == NULL)
        return NULL;

    else
    {

        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }

        else if (root->left == NULL)
        {
            node_tree* temp = root;
            root = root->right;
            free(temp);
            temp = NULL;
        }

        else if (root->right == NULL)
        {
            node_tree* temp = root;
            root = root->left;
            free(temp);
            temp = NULL;
        }

        else
        {
            strcpy_s(root->name, sizeof root->name, root->right->name);
            root->right = delete_simple_tree_node(root->right, root->right->name);
        }
    }
    return root;
}

void delete_tree_node_transversal(node_tree* root, char delete_name[])
{
    node_tree* temp = search_node_tree_BT(root, delete_name);
    if (temp)
        temp = delete_simple_tree_node(temp, temp->name);
}

void BT_delete_tree_node(tree_list* tree, char delete_name[])
{
    delete_tree_node_transversal(tree->root, delete_name);
    tree->tree_height = bst_find_height(tree);
    tree->nr_nodes--;
}

node_tree* search_node_tree_BT(node_tree* root, char key[])
{
    if (root == NULL)
    {
        return NULL;
    }

    bst_queue_list* list = create_bst_queue_list();
    bst_enqueue_queue_list(list, root);

    while (list->front != NULL)
    {
        node_tree* temp = bst_top_elem_queue_list(list);
        bst_dequeue_queue_list(list);

        if (strcmp(temp->name, key) == 0)
        {
            return temp;
        }
        if (temp->left != NULL)
            bst_enqueue_queue_list(list, temp->left);

        if (temp->right != NULL)
            bst_enqueue_queue_list(list, temp->right);
    }
    return NULL;
}

void search_node_BT(node_tree* root, char key[])
{
    if (root == NULL)
    {
        printf("\nThe value %s is not in the list\n", key);
        return;
    }

    bst_queue_list* list = create_bst_queue_list();
    bst_enqueue_queue_list(list, root);

    while (list->front != NULL)
    {
        node_tree* temp = bst_top_elem_queue_list(list);
        bst_dequeue_queue_list(list);

        if (strcmp(temp->name, key) == 0)
        {
            printf("\nThe value %s is in the list\n", key);
            return;
        }
        if (temp->left != NULL)
            bst_enqueue_queue_list(list, temp->left);
           
        if (temp->right != NULL)
            bst_enqueue_queue_list(list, temp->right);
    }

    printf("\nThe value %s is not in the list\n", key);
}

void BT_search(tree_list* tree, char key[])
{
    search_node_BT(tree->root, key);
}

int node_find_height(node_tree* root)
{
    if (root == NULL)
        return -1;
    return max(node_find_height(root->left), node_find_height(root->right)) + 1;
}

int bst_find_height(tree_list* tree)
{
    return node_find_height(tree->root);
}

void bst_transversal_order(tree_list* tree)
{
    if (tree->root == NULL) return;

    bst_queue_list* lista = malloc(sizeof(bst_queue_list));
    bst_init_queue_list(lista);

    bst_enqueue_queue_list(lista, tree->root);

    while (lista->front != NULL)
    {
        node_tree* current = bst_top_elem_queue_list(lista);
        printf("%s, ", current->name);
        if (current->left != NULL) bst_enqueue_queue_list(lista, current->left);
        if (current->right != NULL) bst_enqueue_queue_list(lista, current->right);
        bst_dequeue_queue_list(lista);
    }
}

void node_preorder(node_tree* root)
{
    if (root == NULL)
        return;
    printf("%s, ", root->name);
    node_preorder(root->left);
    node_preorder(root->right);
}

void tree_preorder(tree_list* tree)
{
    if (tree->root == NULL)
        printf("The Tree list is empty");
    node_preorder(tree->root);
}

void node_inorder(node_tree* root)
{
    if (root == NULL)
        return;
    node_inorder(root->left);
    printf("%s, ", root->name);
    node_inorder(root->right);
}

void tree_inorder(tree_list* tree)
{
    if (tree->root == NULL)
        printf("The Tree list is empty");
    node_inorder(tree->root);
}

void node_postorder(node_tree* root)
{
    if (root == NULL)
        return;
    node_postorder(root->left);
    node_postorder(root->right);
    printf("%s, ", root->name);
}

void tree_postorder(tree_list* tree)
{
    if (tree->root == NULL)
        printf("The Tree list is empty");
    node_postorder(tree->root);
}

void bst_free(tree_list* tree)
{
    if (tree->root == NULL) return;

    bst_queue_list* lista = malloc(sizeof(bst_queue_list));
    bst_init_queue_list(lista);

    bst_enqueue_queue_list(lista, tree->root);

    while (lista->front != NULL)
    {
        node_tree* current = bst_top_elem_queue_list(lista);
        if (current->left != NULL) bst_enqueue_queue_list(lista, current->left);
        if (current->right != NULL) bst_enqueue_queue_list(lista, current->right);
        bst_dequeue_queue_list(lista);
        free(current);
        current = NULL;
    }

    bst_free_queue_list(lista);
}

char* bst_return_min_value(tree_list* tree)
{
    if (tree->root == NULL)
    {
        printf("\nThe tree list is empty\n");
        return "ERROR";
    }

    node_tree* current = tree->root;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current->name; 
}

char* BT_return_min_value(tree_list* tree)
{
    if (tree->root == NULL)
    {
        printf("\nThe tree list is empty\n");
        return "ERROR";
    }

    char* min_name = tree->root->name;

    bst_queue_list* list = create_bst_queue_list();
    bst_enqueue_queue_list(list, tree->root);

    while (list->front != NULL)
    {
        node_tree* temp = bst_top_elem_queue_list(list);
        bst_dequeue_queue_list(list);

        if (strcmp(temp->name, min_name) < 0)
        {
            min_name = temp->name;
        }
        if (temp->left != NULL)
            bst_enqueue_queue_list(list, temp->left);

        if (temp->right != NULL)
            bst_enqueue_queue_list(list, temp->right);
    }

    return min_name;
}

char* bst_return_max_value(tree_list* tree)
{
    if (tree->root == NULL)
    {
        printf("\nThe tree list is empty\n");
        return "ERROR";
    }

    node_tree* current = tree->root;

    while (current->right != NULL)
    {
        current = current->right;
    }

    return current->name;
}

char* BT_return_max_value(tree_list* tree)
{
    if (tree->root == NULL)
    {
        printf("\nThe tree list is empty\n");
        return "ERROR";
    }

    char* max_name = tree->root->name;

    bst_queue_list* list = create_bst_queue_list();
    bst_enqueue_queue_list(list, tree->root);

    while (list->front != NULL)
    {
        node_tree* temp = bst_top_elem_queue_list(list);
        bst_dequeue_queue_list(list);

        if (strcmp(temp->name, max_name) > 0)
        {
            max_name = temp->name;
        }
        if (temp->left != NULL)
            bst_enqueue_queue_list(list, temp->left);

        if (temp->right != NULL)
            bst_enqueue_queue_list(list, temp->right);
    }

    return max_name;
}

_Bool is_node_BST(node_tree* root)
{
    if (root == NULL)
        return true;
    else if (root->left == NULL && root->right == NULL)
        return true;
    else if (root->left == NULL && strcmp(root->name, root->right->name) < 0)
        return true;
    else if ((strcmp(root->name, root->left->name) > 0 || strcmp(root->name, root->left->name) == 0) && root->right == NULL)
        return true;
    else if ((strcmp(root->name, root->left->name) > 0 || strcmp(root->name, root->left->name) == 0) && strcmp(root->name, root->right->name) < 0)
        return true;
    else 
        return false;
}

_Bool is_BT_BST(tree_list* tree)
{
    if (tree->root == NULL)
    {
        return true;
    }

    if (tree->root->left == NULL && tree->root->right == NULL)
        return true;
    

    bst_queue_list* list = create_bst_queue_list();
    bst_enqueue_queue_list(list, tree->root);

    while (list->front != NULL)
    {
        node_tree* temp = bst_top_elem_queue_list(list);
        bst_dequeue_queue_list(list);
        if (!is_node_BST(temp))
            return false;

        if (temp->left != NULL)
            bst_enqueue_queue_list(list, temp->left);

        if (temp->right != NULL)
            bst_enqueue_queue_list(list, temp->right);

    }

    return true;
}


void bst_init_queue_list(bst_queue_list* list)
{
    list->front = malloc(sizeof(bst_node_ql));
    list->front = NULL;
    list->rear = malloc(sizeof(bst_node_ql));
    list->rear = NULL;
}

bst_queue_list* create_bst_queue_list()
{
    bst_queue_list* list = malloc(sizeof(bst_queue_list));
    bst_init_queue_list(list);

    return list;
}

node_tree* bst_top_elem_queue_list(bst_queue_list* list)
{
    return list->front->tree_node;
}

//We consider last inserted element(Enqueue) in the list to be the last one in the linked list.
//So if we Enqueue an element, we will add it to the back of the list using rear pointer. - O(1)
void bst_enqueue_queue_list(bst_queue_list* list, node_tree* new_tree_node)
{

        bst_node_ql* newNode;
        while (1) {
            newNode = malloc(sizeof(bst_node_ql));
            if (newNode != NULL) {
                break;
            }
        }
        newNode->next = NULL;
        newNode->tree_node = new_tree_node;


        if (list->front == NULL)
        {
            list->front = newNode;
            list->rear = newNode;
        }

        else
        {
            list->rear->next = newNode;
            list->rear = newNode;
        }
}

//We consider first inserted element in the list to be on position 0 (first element in the list - front.
//If we Dequeue an element, we will remove the first element from the list and make the front to point to the next element in the list.
//If the list is empty we wil receive an error
void bst_dequeue_queue_list(bst_queue_list* list)
{
    bst_node_ql* p = list->front;

    if (p->next == NULL)
    {
        list->front = NULL;
        list->rear = NULL;
    }

    else
    {
        list->front = list->front->next;
    }
    free(p);
    p = NULL;
}

void bst_free_queue_list(bst_queue_list* list)
{
    if (list != NULL)
    {
        bst_node_ql* curent = list->front;
        while (curent != NULL)
        {
            bst_node_ql* aux = curent;

            curent = curent->next;
            free(aux);
            aux = NULL;
        }
    }

    bst_init_queue_list(list);
}