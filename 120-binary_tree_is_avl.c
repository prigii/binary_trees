#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks binary search tree validity of a binary tree
 * @tree: pointer to root node of tree to be checked
 * Return: 1 if tree is a valid binary search tree otherwise 0
 */

int binary_tree_is_avl(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0; // If tree is NULL, return 0
    }

    int height = 0;
    return is_avl_helper(tree, &height);
}

/**
 * binary_tree_is_height - checks binary search tree validity of a binary tree
 * @tree: pointer to root node of tree to be checked
 * Return: 1 if tree is a valid binary search tree otherwise 0
 */

int binary_tree_height(const binary_tree_t *tree) {
    if (tree == NULL) {
        return -1;
    }

    int left_height = binary_tree_height(tree->left);
    int right_height = binary_tree_height(tree->right);

    return 1 + ((left_height > right_height) ? left_height : right_height);
}

/**
 * bool is_avl_helper - checks binary search tree validity of a binary tree
 * @tree: pointer to root node of tree to be checked
 * @height: height of the tree
 * Return: 1 if tree is a valid binary search tree otherwise 0
 */ 

bool is_avl_helper(const binary_tree_t *tree, int *height) {
    if (tree == NULL) {
        *height = -1;
        return true;
    }

    int left_height = 0;
    int right_height = 0;

    bool left_is_avl = is_avl_helper(tree->left, &left_height);
    bool right_is_avl = is_avl_helper(tree->right, &right_height);

    *height = 1 + ((left_height > right_height) ? left_height : right_height);

    int height_difference = abs(left_height - right_height);

    return left_is_avl && right_is_avl && height_difference <= 1;
}
