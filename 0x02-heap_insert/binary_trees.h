#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
int n;
struct binary_tree_s *parent;
struct binary_tree_s *left;
struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

int count_node(heap_t *root);
heap_t *find_parent_node(heap_t *root, int k);
void swap_node(heap_t **root, heap_t *new);
void heapify(heap_t **root, heap_t *new);
heap_t *heap_insert(heap_t **root, int value);

#endif /* _BINARY_TREES_H_ */
