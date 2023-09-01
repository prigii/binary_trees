#include "binary_trees.h"

/**
 * binary_tree_is_full - checks whether binary tree is full or not
 * @tree: pointer to root node of tree to be checked
 * Return: 1 if tree is full, 0 if not full or is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	if (tree->right && tree->left)
		return (binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right));

	return (0);
}
