#include "binary_trees.h"

/**
 * binary_tree_sibling - finds sibling of a node
 * @node: pointer to node whose sibling is to be found
 * Return: pointer to sibling node, NULL if node, parent are NULL or no sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
