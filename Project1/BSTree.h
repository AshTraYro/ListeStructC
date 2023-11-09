#ifndef BSTREE_H
#define BSTREE_H
#pragma once

typedef struct node_tree
{
    char name[32];
    struct node_tree* left;
    struct node_tree* right;
}node_tree;

typedef struct bst_node_ql
{
    node_tree* tree_node;
    struct bst_node_ql* next;
}bst_node_ql;

typedef struct tree_list
{
    node_tree* root;
    int nr_nodes;
    int tree_depth;
    int tree_height;
}tree_list;

//We consider that the front pointer points to the first element of the linked list and will be the position where we Dequeue (remove elements) - O(1)
//We consider that the rear pointer points to the last element of the linked list and will be the position where we Enqueue (add elements) - O(1)
typedef struct bst_queue_list
{
    bst_node_ql* front;
    bst_node_ql* rear;

}bst_queue_list;

void bst_init_queue_list(bst_queue_list* list);

bst_queue_list* create_bst_queue_list();

void bst_enqueue_queue_list(bst_queue_list* list, node_tree* new_tree_node);

void bst_dequeue_queue_list(bst_queue_list* list);

void bst_free_queue_list(bst_queue_list* list);

node_tree* bst_top_elem_queue_list(bst_queue_list* list);

void bst_init_tree_list(tree_list* list);

node_tree* get_new_node_tree(char new_name[]);

node_tree* insert_tree_node(node_tree* root, char new_name[]);

void bst_insert(tree_list* tree, char new_name[]);

tree_list* BST_create_tree_list();

node_tree* delete_tree_node(node_tree* root, char delete_name[]);

void BST_delete_tree_node(tree_list* tree, char delete_name[]);

void search_node_BST(node_tree* root, char key[]);

void BST_search(tree_list* tree, char key[]);

node_tree* insert_tree_node_transversal(node_tree* root, char new_name[]);

void BT_insert_transversal(tree_list* tree, char new_name[]);

tree_list* BT_create_tree_list_transversal();

node_tree* delete_simple_tree_node(node_tree* root, char delete_name[]);

void delete_tree_node_transversal(node_tree* root, char delete_name[]);

node_tree* search_node_tree_BT(node_tree* root, char key[]);

void BT_delete_tree_node(tree_list* tree, char delete_name[]);

void search_node_BT(node_tree* root, char key[]);

void BT_search(tree_list* tree, char key[]);

int node_find_height(node_tree* root);

int bst_find_height(tree_list* tree);

void bst_transversal_order(tree_list* tree);

void node_preorder(node_tree* root);

void tree_preorder(tree_list* tree);

void node_inorder(node_tree* root);

void tree_inorder(tree_list* tree);

void node_postorder(node_tree* root);

void tree_postorder(tree_list* tree);

void bst_free_node(node_tree* root);

void bst_free(tree_list* tree);

char* bst_return_min_value(tree_list* tree);

char* BT_return_min_value(tree_list* tree);

char* bst_return_max_value(tree_list* tree);

char* BT_return_max_value(tree_list* tree);

_Bool is_node_BST(node_tree* root);

_Bool is_BT_BST(tree_list* tree);

#endif
