#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: inserted node or NULL
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *root, *tmp;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}
	root = *tree;
	while (root)
	{
		tmp = root;
		if (root->n == value)
			return (NULL);
		else if (root->n > value)
			root = root->left;
		else if (root->n < value)
			root = root->right;
	}
	new = binary_tree_node(NULL, value);
	if (tmp->n < value)
		tmp->right = new;
	else
		tmp->left = new;
	new->parent = tmp;
	return (new);
}
