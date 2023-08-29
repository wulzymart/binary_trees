#include "binary_trees.h"
/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 * @parent: parent node to insert into
 * @value: value to insert
 * Return: newly created node
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	/* create node */
	new = binary_tree_node(parent, value);

	/* if parent has left child */
	if (parent->left)
	{
		/* assign new node as parent to the old left child */
		parent->left->parent = new;
		/* set left child of new node to old left child */
		new->left = parent->left;
	}
	/* set left child of parent to new node*/
	parent->left = new;

	/* return new node */
	return (new);
}
