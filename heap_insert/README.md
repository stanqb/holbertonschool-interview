# Heap Insert

## Description

This project implements binary tree operations in C, focusing on a **Max Binary Heap** insertion. It is part of the Holberton School interview preparation curriculum.

## Requirements

- Ubuntu 14.04 LTS
- GCC 4.8.4
- Flags: `-Wall -Werror -Wextra -pedantic`
- Betty coding style

## Data Structures

```c
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
```

## Files

| File | Description |
|------|-------------|
| `binary_trees.h` | Header file with structures and prototypes |
| `0-binary_tree_node.c` | Creates a binary tree node |

## Tasks

### 0. New node

**Prototype:** `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`

Creates a new binary tree node with the given `value` and `parent`. Returns a pointer to the new node, or `NULL` on failure.
