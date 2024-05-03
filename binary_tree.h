#ifndef ALGODAT_BINARY_TREE_H
#define ALGODAT_BINARY_TREE_H

#include "stdbool.h"

typedef int T_DATA;

typedef struct T_TREE_NODE {
    T_DATA value;
    struct T_TREE_NODE *left;
    struct T_TREE_NODE *right;
    unsigned int height;
} T_TREE_NODE;

T_TREE_NODE *create_node(T_DATA);
void free_tree(T_TREE_NODE **);

bool is_empty(T_TREE_NODE *);
bool is_leaf(T_TREE_NODE *);
bool is_half_leaf(T_TREE_NODE *);

int get_balance(T_TREE_NODE *);
void update_node(T_TREE_NODE *);

void print_node(T_TREE_NODE *);
void print_tree(T_TREE_NODE *);
void print_inorder(T_TREE_NODE *);
void print_preorder(T_TREE_NODE *);
void print_postorder(T_TREE_NODE *);

bool insert_node(T_DATA, T_TREE_NODE **);
bool delete_node(T_DATA, T_TREE_NODE **);

T_TREE_NODE *find_node(T_DATA, T_TREE_NODE *);


#endif //ALGODAT_BINARY_TREE_H
