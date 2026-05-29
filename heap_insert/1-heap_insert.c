#include <stdlib.h>
#include "binary_trees.h"

/**
 * tree_size - Returns the size of a binary tree
 *
 * @tree: Pointer to the root node
 *
 * Return: Size of the tree
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_insert_parent - Gets the parent node where the next insert should go
 *
 * @root: Pointer to the root of the heap
 * @size: Current size of the heap
 *
 * Return: Pointer to the parent node
 */
static heap_t *get_insert_parent(heap_t *root, size_t size)
{
	size_t path;
	size_t bits;
	heap_t *node;

	bits = 1;
	while ((size_t)(1 << bits) <= size)
		bits++;
	bits--;

	node = root;
	while (bits > 1)
	{
		bits--;
		path = (size >> bits) & 1;
		if (path == 0)
			node = node->left;
		else
			node = node->right;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the new node
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent;
	heap_t *node;
	size_t size;
	int tmp;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = tree_size(*root);
	parent = get_insert_parent(*root, size + 1);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = node;
	else
		parent->right = node;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}

	return (node);
}
