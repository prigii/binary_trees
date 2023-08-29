#include "binary_header.h"

/**
 * binary_tree_inorder - uses in-order traversal to go through a binary tree
 * @tree: tree to be traversed
 * @func: pointer to function to be called for each node
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int)) {
    if (tree == NULL || func == NULL) {
        return; // If tree or func is NULL, do nothing
    }

    // Traverse the left subtree in in-order
    binary_tree_inorder(tree->left, func);

    // Call the function for the current node
    func(tree->value);

    // Traverse the right subtree in in-order
    binary_tree_inorder(tree->right, func);
}

