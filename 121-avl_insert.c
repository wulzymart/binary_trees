#include "binary_trees.h"
/**
 * insert_hlp - helper for avl insertion
 * @tree: pointer to root node
 * @value: value to insert
 * Return: pointer to created node or NULL
*/
avl_t *insert_hlp(avl_t **tree, avl_t *parent, avl_t **new,  int value)
{
    int bal;

    if (!(*tree))
        return (*new = binary_tree_node(parent, value));
    if (value < (*tree)->n)
        (*tree)->left = insert_hlp(&(*tree)->left, *tree, new, value);
    else if (value > (*tree)->n)
        (*tree)->right = insert_hlp(&(*tree)->right, (*tree), new, value);
    else
        return ((*tree));
    bal = binary_tree_balance((*tree));
    if (bal > 1 && value < (*tree)->left->n)
        *tree = binary_tree_rotate_right(*tree);
    else if (bal < -1 && value > (*tree)->right->n)
        *tree = binary_tree_rotate_left(*tree);
    else if (bal > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        *tree = binary_tree_rotate_right(*tree);
    }
    else if (bal < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        *tree = binary_tree_rotate_left(*tree);
    }
    return (*tree);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root of the AVL tree for inserting the value
 * @value: value to store in the node to be inserted
 * Return: pointer to created node or NULL
*/
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new = NULL;

    if (!tree)
        return (NULL);
    if (!*tree)
        return (*tree = binary_tree_node(*tree, value));
    insert_hlp(tree, *tree, &new, value);
    return (new);
}
