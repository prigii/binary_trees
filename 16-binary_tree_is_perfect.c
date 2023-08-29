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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to root node of tree to be checked
 * Return: 1 if tree is perfect, 0 if not perfect or is NULL
 */


int binary_tree_is_perfect(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0; // If tree is NULL, not a perfect tree
    }

    // Calculate the height of the left and right subtrees
    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    // Check if the tree is balanced and the left and right subtrees have the same height
    if (left_height == right_height) {
        // Check if the left and right subtrees are also perfect
        return binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right);
    }

    return 0;
}
