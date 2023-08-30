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
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: lowest common ancestor or NULL if not found
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (!first || !second)
		return (NULL);
	/* get the depth of both nodes */
	first_depth = binary_tree_depth(first);
	second_depth =  binary_tree_depth(second);
	/* traverse until both nodes are of equal depth */
	for (; first_depth > second_depth; first_depth--)
		first = first->parent;
	for (; second_depth > first_depth ; second_depth--)
		second = second->parent;
	/* now traverse both upwards, return when they are equal */
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
