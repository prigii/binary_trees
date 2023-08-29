#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: tree whose leaves are to be counted
 * Return: number of leaves, 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0; // If tree is NULL, there are no leaves
    }

    if (tree->left == NULL && tree->right == NULL) {
        return 1; // If node is a leaf, return 1
    }

    // Recursively count the leaves in the left and right subtrees
    size_t left_leaves = binary_tree_leaves(tree->left);
    size_t right_leaves = binary_tree_leaves(tree->right);

    return left_leaves + right_leaves;
}
