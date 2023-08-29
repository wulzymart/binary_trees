#include "binary_trees.h"
/**
 * power - returns exponential calculation
 * @base: base to get the power
 * @power: exponent
 * Return: result
*/
size_t power(long base, int power)
{
	size_t result = base;

	if (power == 0)
		return (1);
	while (power > 1)
	{
		result *= base;
		power--;
	}
	return (result);
}
/**
 * tree_size -  measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size.
 * Return: size of tree
*/
size_t tree_size(const binary_tree_t *tree)
{
	/* recursion guard */
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}
/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: Height of tree
*/
size_t tree_height(const binary_tree_t *tree)
{
	size_t h = 0;

	while (tree)
	{
		h++;
		tree = tree->left;
	}
	return (h - 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect otherwise 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t size = 0;
	size_t calc_size = 0;
	int height = 0;

	if (!tree)
		return (0);
	size = tree_size(tree);
	height = tree_height(tree);
	calc_size = power(2, height + 1) - 1;
	return (size == calc_size);
}
