#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * count_node - count the number of nodes of a Binary Tree
 * @root: pointer to the root node of the Tree
 * Return: number of nodes in the tree
 */
int count_node(heap_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + count_node(root->left) + count_node(root->right));
}


/**
 * find_parent_node - find the parent node to insert
 * @root: pointer to the root node of the Tree
 * @k : position of the node to be inserted
 * Return: pointer parent of the node to be inserted
 */
heap_t *find_parent_node(heap_t *root, int k)
{
	if (k == 1)
		return (root);
	if (k % 2 == 0)
		return (find_parent_node(root, k / 2)->left);
	return (find_parent_node(root, k / 2)->right);
}


/**
 * swap_node - swap a node with his parent
 * @root: double pointer to the root node of the Tree
 * @new: new created node
 * Return: Void
 */
void swap_node(heap_t **root, heap_t *new)
{
	heap_t *templeft, *tempright, *temppar;

	templeft = new->left;
	tempright = new->right;
	temppar = new->parent->parent;
	if (new->parent->left == new)
	{
		new->left = new->parent;
		new->left->parent = new;
		new->right = new->parent->right;
		if (new->right)
			new->right->parent = new;
	}
	else
	{
		new->right = new->parent;
		new->right->parent = new;
		new->left = new->parent->left;
		if (new->left)
			new->left->parent = new;
	}
	new->parent->left = templeft;
	new->parent->right = tempright;
	if (templeft)
		new->parent->left->parent = new->parent;
	if (tempright)
		new->parent->right->parent = new->parent;
	if (temppar == NULL)
		*root = new;
	else
	{
		if (temppar->left == new->parent)
			temppar->left = new;
		else
			temppar->right = new;
	}
	new->parent->parent = new;
	new->parent = temppar;
}



/**
 * heapify - remaxify heap tree
 * @root: double pointer to the root node of the Tree
 * @new: new created node
 * Return: Void
 */
void heapify(heap_t **root, heap_t *new)
{
	while (new != *root && new->parent->n < new->n)
	{
		swap_node(root, new);
	}
}




/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int nb_node;
	heap_t *new, *parent;

	new = malloc(sizeof(heap_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;

	if (root == NULL || *root == NULL)
	{
		*root = new;
		return (new);
	}

	nb_node = count_node(*root);
	parent = find_parent_node(*root, (nb_node + 1) / 2);
	new->parent = parent;
	if ((nb_node + 1) % 2 == 0)
		parent->left = new;
	else
		parent->right = new;

	heapify(root, new);
	return (new);
}
