#include "binary_trees.h"
/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count number of nodes.
 * Return: number of nodes with atleast one child
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* recursion guard */
	if (!tree)
		return (0);
	/* if there is either left or right child add 1 else 0*/
	return ((tree->left || tree->right ? 1 : 0)
	+ binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
