#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * @parent: pointer to parent node to insert left-child in
 * @value: value to store in new node
 * Return: Pointer to newly created node NULL on failure NULL if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value) {
    if (parent == NULL) {
        return NULL; // Cannot insert as left child if parent is NULL
    }

    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL) {
        return NULL; // Allocation failure
    }

    new_node->value = value;
    new_node->parent = parent;
    new_node->left = parent->left; // Move the current left child to the new node's left child
    new_node->right = NULL;

    if (parent->left != NULL) {
        parent->left->parent = new_node; // Update the parent of the current left child
    }

    parent->left = new_node; // Set the new node as the left child of the parent

    return new_node;
}



