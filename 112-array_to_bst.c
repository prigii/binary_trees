#include "binary_trees.h"

/**
 * array_to_bst - converts an array to BST
 * @array: pointer to array to be converted
 * @size: size of array
 * Return: pointer to node containing an int equal to `root` else NULL
 */


bst_t *array_to_bst(int *array, size_t size) {
    bst_t *root = NULL;

    for (size_t i = 0; i < size; ++i) {
        bst_insert(&root, array[i]);
    }

    return root;
}
