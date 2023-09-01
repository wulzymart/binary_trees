#include "binary_trees.h"
/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to root of AVL BST
*/
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t i;

	if (!array || !size)
		return (NULL);
	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);
	return (root);
}
