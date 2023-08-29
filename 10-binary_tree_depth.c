#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: node whose depth is to be measured
 * Return: depth of the node, 0 if tree is NULL
 */


size_t binary_tree_depth(const binary_tree_t *node) {
    if (node == NULL) {
        return 0; // If node is NULL, depth is 0
    }

    size_t depth = 0;
    while (node->parent != NULL) {
        depth++;
        node = node->parent;
    }

    return depth;
}
