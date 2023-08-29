#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs left rotation of a binary tree
 * @tree: pointer to root node of tree to be rotated
 * Return: pointer to new root node of rotated tree or NULL upon failure
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree) {
    if (tree == NULL || tree->right == NULL) {
        return tree; // Cannot rotate, return original tree
    }

    binary_tree_t *new_root = tree->right; // New root after rotation
    binary_tree_t *pivot = new_root->left; // Pivot node

    // Update parent pointers
    new_root->parent = tree->parent;
    if (tree->parent != NULL) {
        if (tree->parent->left == tree) {
            tree->parent->left = new_root;
        } else {
            tree->parent->right = new_root;
        }
    }

    tree->parent = new_root;
    tree->right = pivot;

    if (pivot != NULL) {
        pivot->parent = tree;
    }

    new_root->left = tree;

    return new_root;
}
