#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: tree whose nodes are to be counted
 * Return: number of nodes counted, 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0; // If tree is NULL, there are no nodes
    }

    if (tree->left != NULL || tree->right != NULL) {
        // If node has at least one child, count this node
        return 1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
    } else {
        return 0; // If node is a leaf (no children), don't count it
    }
}

