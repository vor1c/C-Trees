#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>


void print_tree_node(T_TREE_NODE *, unsigned int, bool *, bool);


bool is_empty(T_TREE_NODE *node) {
    return node == NULL;
}

void print_node(T_TREE_NODE *node) {
    if (is_empty(node)) {
        printf("No node provided\n");
    } else {
        printf("%d (h=%d)\n", node->value, node->height);
    }
}

void print_tree(T_TREE_NODE *root) {
    printf("*****************************************\n");
    printf("TREE:\n");
    if (is_empty(root)) {
        printf("Tree does not contain any elements!\n");
    } else {
        bool depth_array[root->height];
        print_tree_node(root, 0, depth_array, false);
    }
    printf("*****************************************\n");
}

void print_tree_node(T_TREE_NODE *node, unsigned int depth, bool *depth_array, bool is_left) {
    if (is_empty(node)) return;

    if (depth > 0) {
        for (int i = 0; i < depth - 1; ++i)
            if (depth_array[i]) printf("    ");
            else printf("|   ");
        printf("%c-- ", (is_left) ? 'L' : 'R');
    }
    print_node(node);

    if (is_empty(node->right))
        depth_array[depth] = true;
    else
        depth_array[depth] = false;
    print_tree_node(node->left, depth + 1, depth_array, true);
    depth_array[depth] = true;
    print_tree_node(node->right, depth + 1, depth_array, false);
}