#include "binary_trees.h"

/**
 * bst_remove - searches for a value in BST
 * @root: pointer to root node of BST to be searched
 * @value: value to be searched in tree
 * Return: pointer to node containing an int equal to `value` else NULL
 */

bst_t *bst_remove(bst_t *root, int value) {
    if (root == NULL) {
        return NULL; // If tree is empty, return NULL
    }

    if (value < root->value) {
        root->left = bst_remove(root->left, value); // Search in the left subtree
    } else if (value > root->value) {
        root->right = bst_remove(root->right, value); // Search in the right subtree
    } else {
        // Found the node to remove
        if (root->left == NULL) {
            bst_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children, replace it with in-order successor
        bst_t *temp = find_min(root->right);
        root->value = temp->value;
        root->right = bst_remove(root->right, temp->value);
    }

    return root;
}

bst_t *find_min(bst_t *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
