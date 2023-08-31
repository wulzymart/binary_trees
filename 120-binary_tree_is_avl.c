
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
 * is_avl - helper function
 * @tree: pointer to node to check
 * Return: 1 if is avl 0 if not
*/
int is_avl(const binary_tree_t *tree)
{
	int lh, rh;

	if (!tree)
		return (1);
	lh = tree->left ?  binary_tree_height(tree->left) + 1 : 0;
	rh = tree->right ? binary_tree_height(tree->right) + 1 : 0;
	return ((abs(lh - rh) <= 1 ? 1 : 0) && is_avl(tree->left)
			&& is_avl(tree->right));

}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!binary_tree_is_bst(tree))
		return (0);
	return (is_avl(tree));
}
