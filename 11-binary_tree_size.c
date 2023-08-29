#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to be measured
 * Return: size of tree, 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0; // If tree is NULL, size is 0
    }

    // Recursively calculate the size of the left and right subtrees
    size_t left_size = binary_tree_size(tree->left);
    size_t right_size = binary_tree_size(tree->right);

    // Return the sum of sizes of the left and right subtrees plus 1 for the current node
    return left_size + right_size + 1;
}

