#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks binary search tree validity of a binary tree
 * @tree: pointer to root node of tree to be checked
 * Return: 1 if tree is a valid binary search tree otherwise 0
 */


int binary_tree_is_bst(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0; // If tree is NULL, it's not a valid BST
    }

    return is_bst_helper(tree, INT_MIN, INT_MAX);
}

/**
 * isbst_helper - checks binary search tree validity of a binary tree
 * @tree: pointer to root node of tree to be checked
 * @min: lower bound of checked nodes
 * @max: upper bound of checked nodes
 * Return: 1 if tree is valid binary search tree otherwise 0
 */

bool is_bst_helper(const binary_tree_t *node, int min_val, int max_val) {
    if (node == NULL) {
        return true; // An empty tree is a valid BST
    }

    // Check if the current node's value is within the allowed range
    if (node->value <= min_val || node->value >= max_val) {
        return false;
    }

    // Recursively check left and right subtrees
    return is_bst_helper(node->left, min_val, node->value) &&
           is_bst_helper(node->right, node->value, max_val);
}
