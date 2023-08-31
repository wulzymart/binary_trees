#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to new root
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_rt, *tmp;

	if (!tree || !tree->right)
		return (tree);
	new_rt = tree->right;
	tmp = new_rt->left;
	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = new_rt;
		else
			tree->parent->right = new_rt;
	}
	new_rt->parent = tree->parent;
	tree->parent = new_rt;
	new_rt->left = tree;
	tree->right = tmp;
	if (tmp)
		tmp->parent = tree;
	return (new_rt);
}
