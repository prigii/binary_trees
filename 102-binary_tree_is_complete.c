#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to root node of tree to be checked
 * Return - 1 if tree is complete, 0 if not complete or tree is NULL
 */

int binary_tree_is_complete(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0; // If tree is NULL, it's not complete
    }

    int is_leaf = 0; // Indicates if we've seen a leaf node

    // Use level-order traversal to check completeness
    binary_tree_t *queue[1000]; // Assuming maximum 1000 nodes
    int front = 0;
    int rear = 0;
    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear) {
        binary_tree_t *current = queue[front++];

        if (current == NULL) {
            is_leaf = 1; // Mark that we've seen a leaf node
        } else {
            // If we've seen a leaf before and the current node is not NULL, it's not complete
            if (is_leaf) {
                return 0;
            }

            queue[rear++] = current->left;
            queue[rear++] = current->right;
        }
    }

    return 1; // If no incomplete pattern is found, the tree is complete
}
