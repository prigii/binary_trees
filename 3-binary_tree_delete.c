#include "binary_trees.h"

/**
 * binary_tree_delete - deletes a whole binary tree
 * @tree: the tree to be deleted
 */


void binary_tree_delete(binary_tree_t *tree) {
    if (tree == NULL) {
        return; // If tree is NULL, do nothing
    }

    // Recursively delete left and right subtrees
    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);

    // Once subtrees are deleted, free the current node
    free(tree);
}



