#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: Height of tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	/* recursion guard */
	if (!tree)
		return (0);
	/* recursively get left height */
	left_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	/* recursively get right height */
	right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;
	/* return the greater height value */
	return (left_height > right_height ? left_height : right_height);
}
