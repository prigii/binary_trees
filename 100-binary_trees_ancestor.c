#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to second node
 * Return: pointer to ancestor node, NULL if no ancestor is found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second) {
    if (first == NULL || second == NULL) {
        return NULL; // If either node is NULL, no common ancestor
    }

    // Find the depths of the nodes
    size_t depth_first = binary_tree_depth(first);
    size_t depth_second = binary_tree_depth(second);

    // Move the deeper node up to the same level as the other node
    while (depth_first > depth_second) {
        first = first->parent;
        depth_first--;
    }
    while (depth_second > depth_first) {
        second = second->parent;
        depth_second--;
    }

    // Move both nodes up in tandem until they meet at the common ancestor
    while (first != NULL && second != NULL && first != second) {
        first = first->parent;
        second = second->parent;
    }

    return (first == NULL || second == NULL) ? NULL : (binary_tree_t *)first;
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: node whose depth is to be measured
 * Return: depth of the node, 0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree) {
    size_t depth = 0;
    while (tree != NULL) {
        tree = tree->parent;
        depth++;
    }
    return depth;
}
