#include "binary_trees.h"

/**
 * binary_tree_sibling - finds sibling of a node
 * @node: pointer to node whose sibling is to be found
 * Return: pointer to sibling node, NULL if node, parent are NULL or no sibling
 */


binary_tree_t *binary_tree_sibling(binary_tree_t *node) {
    if (node == NULL || node->parent == NULL) {
        return NULL; // If node is NULL or has no parent, return NULL
    }

    // Check if the node is the left child of its parent
    if (node->parent->left == node) {
        return node->parent->right; // Return the right child of the parent
    }

    // If the node is the right child of its parent or not a child at all
    return node->parent->left; // Return the left child of the parent
}
