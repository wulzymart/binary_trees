#include "binary_trees.h"
#include <stdio.h>
/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: Height of tree
*/
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	/* recursion guard */
	if (!tree)
		return (0);
	/* recursively get left height */
	left_height = tree->left ? tree_height(tree->left) + 1 : 1;
	/* recursively get right height */
	right_height = tree->right ? tree_height(tree->right) + 1 : 1;
	/* return the greater height value */
	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (!tree)
		return (0);
	left = tree_height(tree->left);
	right = tree_height(tree->right);
	return (left - right);
}
