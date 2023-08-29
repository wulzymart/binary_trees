#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves.
 * Return: number of leaves of tree
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	/* recursion guard */
	if (!tree)
		return (0);
	/* if there is no left child or no right child add 1 else 0*/
	return ((!tree->left && !tree->right ? 1 : 0)
	+ binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
