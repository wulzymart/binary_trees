#include "binary_trees.h"
/**
 * binary_tree_size -  measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size.
 * Return: size of tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* recursion guard */
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
/**
 * is_complete - helper function to recursively check each nodes completeness
 * @tree: pointer to the root node
 * @i: index of node if in an array
 * @size: size of the tree
 * Return: 1 (true) or 0 (false)
*/
int is_complete(const binary_tree_t *tree, unsigned int i, unsigned int size)
{
	/* if node is NULL, then tree is complete*/
	if (!tree)
		return (1);

	/* if index is greater more than the array size tree is not complete*/
	if (i >= size)
		return (0);

	/* recursively check left and right sides */
	/* left should have index 2i + 1 and right: 2i + 2 */
	return (is_complete(tree->left, 2 * i + 1, size) &&
			is_complete(tree->right, 2 * i + 2, size));
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 or 0
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	/* guard */
	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	/* check index of each node for completeness starting from root*/
	return (is_complete(tree, 0, size));
}

