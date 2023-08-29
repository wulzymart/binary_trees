#include "binary_trees.h"
/**
 * binary_tree_postorder - goes through a binary tree using
 * post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func:  pointer to a function to call for each node.
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	/* recursion guard */
	if (!tree || !func)
		return;
	/* traverse left */
	binary_tree_postorder(tree->left, func);
	/* traverse right */
	binary_tree_postorder(tree->right, func);
	/* call function on root value */
	func(tree->n);
}
