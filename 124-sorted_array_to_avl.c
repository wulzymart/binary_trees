#include "binary_trees.h"
/**
 * s_arr - helper
 * @array: pointer to the first element of the array to be converted
 * @start: starting index
 * @end: end index
 * @root: pointer to root node
*/
void s_arr(int *array, int start, int end, avl_t **root)
{
	int mid;
	avl_t *node = NULL;

	if (end - start > 1)
	{
		mid =  (end - start) / 2 + start;
		node = binary_tree_node(*root, array[mid]);
		if (array[mid] > (*root)->n)
			(*root)->right = node;
		else if (array[mid] < (*root)->n)
			(*root)->left = node;
		s_arr(array, start, mid, &node);
		s_arr(array, mid, end, &node);
	}

}
/**
 * sorted_array_to_avl- builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to root of AVL BST
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	int mid;

	if (!array || !size)
		return (NULL);
	mid = (size - 1) / 2;
	root = binary_tree_node(root, array[mid]);
	s_arr(array, -1, mid, &root);
	s_arr(array, mid, size, &root);
	return (root);
}
