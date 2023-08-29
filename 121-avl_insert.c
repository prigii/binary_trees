#include "binary_trees.h"

avl_t *avl_insert(avl_t **tree, int value) {
    if (tree == NULL) {
        return NULL;
    }

    *tree = avl_insert_recursive(*tree, value);
    return *tree;
}

int avl_height(const avl_t *node) {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

int balance_factor(const avl_t *node) {
    return avl_height(node->left) - avl_height(node->right);
}

avl_t *rotate_left(avl_t *node) {
    avl_t *new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;

    // Update heights
    node->height = 1 + (avl_height(node->left) > avl_height(node->right) ? avl_height(node->left) : avl_height(node->right));
    new_root->height = 1 + (avl_height(new_root->left) > avl_height(new_root->right) ? avl_height(new_root->left) : avl_height(new_root->right));

    return new_root;
}

avl_t *rotate_right(avl_t *node) {
    avl_t *new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;

    // Update heights
    node->height = 1 + (avl_height(node->left) > avl_height(node->right) ? avl_height(node->left) : avl_height(node->right));
    new_root->height = 1 + (avl_height(new_root->left) > avl_height(new_root->right) ? avl_height(new_root->left) : avl_height(new_root->right));

    return new_root;
}

avl_t *avl_insert_recursive(avl_t *root, int value) {
    if (root == NULL) {
        avl_t *new_node = malloc(sizeof(avl_t));
        if (new_node == NULL) {
            return NULL;
        }
        new_node->value = value;
        new_node->height = 0;
        new_node->parent = NULL;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (value < root->value) {
        root->left = avl_insert_recursive(root->left, value);
        root->left->parent = root;
    } else if (value > root->value) {
        root->right = avl_insert_recursive(root->right, value);
        root->right->parent = root;
    }

    // Update height of the current node
    root->height = 1 + (avl_height(root->left) > avl_height(root->right) ? avl_height(root->left) : avl_height(root->right));

    return avl_balance(root);
}

avl_t *avl_balance(avl_t *node) {
    int balance = balance_factor(node);

    // Left heavy
    if (balance > 1) {
        if (balance_factor(node->left) < 0) {
            node->left = rotate_left(node->left);
        }
        return rotate_right(node);
    }
    // Right heavy
    else if (balance < -1) {
        if (balance_factor(node->right) > 0) {
            node->right = rotate_right(node->right);
        }
        return rotate_left(node);
    }
    // Balanced
    return node;
}
