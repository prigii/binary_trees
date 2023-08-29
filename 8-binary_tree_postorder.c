#include "binary_trees.h"

/**
 * binary_tree_postorder - uses post-order traversal to go through binary tree
 * @tree: tree to be traversed
 * @func: pointer to function to be called for each node
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int)) {
    if (tree == NULL || func == NULL) {
        return; // If tree or func is NULL, do nothing
    }

    // Traverse the left subtree in post-order
    binary_tree_postorder(tree->left, func);

    // Traverse the right subtree in post-order
    binary_tree_postorder(tree->right, func);

    // Call the function for the current node
    func(tree->value);
}
