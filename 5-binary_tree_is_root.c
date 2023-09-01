#include "binary_trees.h"

/**
 * binary_tree_is_root -checks whether a node is root
 * @node: node to be checked
 * Return: 1 if node is root, 0 if not root or is NULL
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	return ((!node || node->parent) ? 0 : 1);
}
