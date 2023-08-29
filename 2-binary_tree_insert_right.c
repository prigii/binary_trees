#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right child of another node
 * @parent: pointer to parent node to insert right-child in
 * @value: value to store in new node
 * Return: Pointer to newly created node NULL on failure NULL if parent is NULL
 */



binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value) {
    if (parent == NULL) {
        return NULL; // Cannot insert as right child if parent is NULL
    }

    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL) {
        return NULL; // Allocation failure
    }

    new_node->value = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = parent->right; // Move the current right child to the new node's right child

    if (parent->right != NULL) {
        parent->right->parent = new_node; // Update the parent of the current right child
    }

    parent->right = new_node; // Set the new node as the right child of the parent

    return new_node;
}



