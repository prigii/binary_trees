#include "binary_trees.h"

/**
 * binary_tree_preorder - uses pre-order traversal to go through a binary tree
 * @tree: tree to be traversed
 * @func: pointer to function to be called for each node
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int)) {
    if (tree == NULL || func == NULL) {
        return; // If tree or func is NULL, do nothing
    }

    // Call the function for the current node
    func(tree->value);

    // Traverse the left subtree in pre-order
    binary_tree_preorder(tree->left, func);

    // Traverse the right subtree in pre-order
    binary_tree_preorder(tree->right, func);
}

