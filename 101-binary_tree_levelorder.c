#include "binary_trees.h"

/**
 * binary_tree_levelorder - uses level-order traversal to traverse binary tree
 * @tree: tree to be traversed
 * @func: pointer to function to be called for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int)) {
    if (tree == NULL || func == NULL) {
        return;
    }

    Queue *queue = createQueue();
    enqueue(queue, tree);

    while (!isQueueEmpty(queue)) {
        const binary_tree_t *current = dequeue(queue);
        func(current->value);

        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }

    freeQueue(queue);
}

Queue *createQueue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, const binary_tree_t *node) {
    QueueNode *newNode = malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

const binary_tree_t *dequeue(Queue *queue) {
    if (queue->front == NULL) {
        return NULL;
    }

    QueueNode *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    const binary_tree_t *node = temp->node;
    free(temp);
    return node;
}

int isQueueEmpty(Queue *queue) {
    return (queue->front == NULL);
}


