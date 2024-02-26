#include "binary_trees.h"
/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 *
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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

    /* If the parent already has a left child, set it as the right child of the new node */
    if (parent->left != NULL)
    {
        new_node->left = parent->left;
        parent->left->parent = new_node;
    }

    /* Set the new node as the left child of the parent */
    parent->left = new_node;

    /* Return the new node */
    return (new_node);
}
