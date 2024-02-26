#include "binary_tree.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 *
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
        return (NULL);

    /* Create a new node */
    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    /* Set the new node's value and parent */
    new_node->n = value;
    new_node->parent = parent;

    /* Set the new node's left and right children to NULL */
    new_node->left = NULL;
    new_node->right = NULL;

    /* If the parent already has a right child, set it as the left child of the new node */
    if (parent->right != NULL)
    {
        new_node->right = parent->right;
        parent->right->parent = new_node;
    }

    /* Set the new node as the right child of the parent */
    parent->right = new_node;

    /* Return the new node */
    return (new_node);
}
