#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs right rotation of a binary tree
 * @tree: pointer to root node of tree to be rotated
 * Return: pointer to new root node of rotated tree or NULL upon failure
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree) {
    if (tree == NULL || tree->left == NULL) {
        return tree; // Cannot rotate, return original tree
    }

    binary_tree_t *new_root = tree->left; // New root after rotation
    binary_tree_t *pivot = new_root->right; // Pivot node

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
    tree->left = pivot;

    if (pivot != NULL) {
        pivot->parent = tree;
    }

    new_root->right = tree;

    return new_root;
}
