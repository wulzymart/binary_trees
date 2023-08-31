#include "binary_trees.h"
/**
 * isBst - helper function
 * @tree: node of pointer to check
 * @left: left node
 * @right: right node
 * Return: 1 is BST else 0
*/
int is_BST(const binary_tree_t *tree, const binary_tree_t *left,
const binary_tree_t *right)
{
	/* if recurssion gets to leaf return true */
	if (!tree)
		return (1);

	/* if there is left and it is greater then root*/
	if (left && tree->n <= left->n)
		return (0);
	/* if there is right and it is greater then root*/
	if (right && tree->n >= right->n)
		return (0);

	/* recursively check left and right side */
	return (is_BST(tree->left, left, tree) &&
	is_BST(tree->right, tree, right));
}

/**
 * binary_tree_is_bst -  checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to root of tree to check
 * Return: 1 if is BST else 0
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_BST(tree, NULL, NULL));
}
