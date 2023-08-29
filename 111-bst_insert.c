#include "binary_trees.h"

/**
 * bst_insert - inserts for a value in BST
 * @tree: pointer to root node of BST to be searched
 * @value: value to be searched in tree
 * Return: pointer to node containing an int equal to `value` else NULL
 */

bst_t *bst_insert(bst_t **tree, int value) {
    if (tree == NULL) {
        return NULL;
    }

    bst_t *new_node = malloc(sizeof(bst_t));
    if (new_node == NULL) {
        return NULL; // Memory allocation failed
    }

    new_node->value = value;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*tree == NULL) {
        *tree = new_node; // If tree is empty, the new node becomes the root
        return new_node;
    }

    bst_t *current = *tree; // Start traversal from the root

    while (1) {
        if (value < current->value) {
            if (current->left == NULL) {
                current->left = new_node;
                new_node->parent = current;
                break;
            }
            current = current->left;
        } else if (value > current->value) {
            if (current->right == NULL) {
                current->right = new_node;
                new_node->parent = current;
                break;
            }
            current = current->right;
        } else {
            free(new_node); // Value already exists, so ignore and free the new node
            return NULL;
        }
    }

    return new_node;
}
