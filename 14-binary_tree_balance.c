#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: the tree whose height is to be measured
 * Return: height of tree, 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0; // If tree is NULL, height is 0
    }

    // Recursively calculate the height of the left and right subtrees
    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    // Return the maximum height between left and right subtrees plus 1 for the current node
    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

/**
 * binary_tree_balance - measures binary tree balance factor
 * @tree: pointer to root node of tree to be measured
 * Return: balance factor, 0 if tree is NULL
 */


int binary_tree_balance(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0; // If tree is NULL, balance factor is 0
    }

    // Calculate the height of the left and right subtrees
    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    // Return the balance factor (difference in heights)
    return (int)(left_height - right_height);
}

