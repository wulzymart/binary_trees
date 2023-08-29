#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the root node of the tree to measure the depth.
 * Return: depth of tree
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	/* traverse form present node to root */
	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
