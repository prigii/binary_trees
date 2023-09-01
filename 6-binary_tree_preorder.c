#include "binary_trees.h"

/**
 * binary_tree_preorder - uses pre-order traversal to go through a binary tree
 * @tree: tree to be traversed
 * @func: pointer to function to be called for each node
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
