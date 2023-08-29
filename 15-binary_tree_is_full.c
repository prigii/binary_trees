#include "binary_trees.h"
/**
 * binary_tree_is_full - checks whether binary tree is full or not
 * @tree: pointer to root node of tree to be checked
 * Return: 1 if tree is full, 0 if not full or is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0; // If tree is NULL, not a full tree
    }

    // If tree is a leaf node, it's a full tree
    if (tree->left == NULL && tree->right == NULL) {
        return 1;
    }

    // If tree has both children, check if both subtrees are full
    if (tree->left != NULL && tree->right != NULL) {
        return binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);
    }

    // If tree has only one child, it's not a full tree
    return 0;
}
