#include "binary_trees.h"
/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func:  pointer to a function to call for each node.
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/*recursion guard*/
	if (!tree || !func)
		return;
	/* call function on level value */
	func(tree->n);
	/* traverse left side */
	binary_tree_preorder(tree->left, func);
	/* traverse right side */
	binary_tree_preorder(tree->right, func);
}
