#include "binary_trees.h"


/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: node to be checked
 * Return: 1 if node a leaf, 0 if not a leaf or NULL
 */

int binary_tree_is_leaf(const binary_tree_t *node) {
    if (node == NULL) {
        return 0; // If node is NULL, not a leaf
    }

    // A leaf node is one that has no children (both left and right are NULL)
    return (node->left == NULL && node->right == NULL);
}

