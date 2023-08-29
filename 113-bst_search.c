#include "binary_trees.h"

/**
 * bst_search - searches for a value in BST
 * @tree: pointer to root node of BST to be searched
 * @value: value to be searched in tree
 * Return: pointer to node containing an int equal to `value` else NULL
 */

bst_t *bst_search(const bst_t *tree, int value) {
    if (tree == NULL) {
        return NULL; // If tree is NULL, or value not found, return NULL
    }

    if (value == tree->value) {
        return (bst_t *)tree; // Found the value in the current node
    } else if (value < tree->value) {
        return bst_search(tree->left, value); // Search in the left subtree
    } else {
        return bst_search(tree->right, value); // Search in the right subtree
    }
}
