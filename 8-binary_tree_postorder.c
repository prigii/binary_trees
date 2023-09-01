#include "binary_trees.h"

/**
 * binary_tree_postorder - uses post-order traversal to go through binary tree
 * @tree: tree to be traversed
 * @func: pointer to function to be called for each node
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
