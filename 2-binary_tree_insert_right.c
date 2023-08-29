#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: parent node to insert into
 * @value: value to insert
 * Return: newly created node
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	/* create node */
	new = binary_tree_node(parent, value);

	/* if parent has right child */
	if (parent->right)
	{
		/* assign new node as parent to the old right child */
		parent->right->parent = new;
		/* set right child of new node to old right child */
		new->right = parent->right;
	}
	/* set right child of parent to new node*/
	parent->right = new;

	/* return new node */
	return (new);
}
