#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 * @parent: parent node
 * @value: value of node
 * Return: newly created node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	/* assign memory for a new node */
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	/* assign the values */
	new->n = value;
	new->left = new->right = NULL;
	new->parent = parent;
	/* return the new node */
	return (new);
}
