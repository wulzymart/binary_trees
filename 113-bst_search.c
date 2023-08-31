#include "binary_trees.h"
/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: found node or NULL
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	while (tree)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n < value)
			tree = tree->right;
		else
			tree = tree->left;
	}
	return (NULL);
}
