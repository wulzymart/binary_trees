#include "binary_trees.h"
#include <stdio.h>
/**
 * get_successor - gets the next inorder successor
 * @node: node to get the successor from
 * Return: value in next successor
*/
int get_successor(bst_t *node)
{
	int val = node->n;

	while (node->left)
	{
		val = node->left->n;
		node = node->left;
	}
	return (val);
}
/**
 * address_parent - helper function to deal with parent pointer
 * @root: node to handle
 * @rep: node to replace with in parent
*/
void address_parent(bst_t *root, bst_t *rep)
{
	if (root->parent)
	{
		if (root->parent->left == root)
			root->parent->left = rep;
		else
			root->parent->right = rep;
	}
}
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: new root or NULL;
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (root)
	{
		if (value < root->n)
			bst_remove(root->left, value);
		else if (value > root->n)
			bst_remove(root->right, value);
		else
		{
			if (!root->right && !root->left)
			{
				if (root->parent)
				{
					address_parent(root, NULL);
				}
				free(root);
				return (NULL);
			}
			else if (!root->left || !root->right)
			{
				tmp = root->left ? root->left : root->right;
				tmp->parent = root->parent;
				address_parent(root, tmp);
				free(root);
				return (tmp);
			}
			root->n = get_successor(root->right);
			root->right = bst_remove(root->right, root->n);
		}
	}
	return (root);
}
