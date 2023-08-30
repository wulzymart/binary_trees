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
/**
 * level_application - calls function for earch level recursively
 * @level: current level
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
*/
void level_application(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 1)
		func(tree->n);
	else
	{
		level_application(tree->left, level - 1, func);
		level_application(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - traverse a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;
	/* recursion*/
	if (!tree)
		return;
	height = binary_tree_height(tree);
	for (i = 0; i <= height + 1; i++)
		level_application(tree, i, func);
}
