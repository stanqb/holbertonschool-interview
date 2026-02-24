Readme · MD
Copier

# Linked List Cycle

## Description

A C function that checks if a singly linked list contains a cycle, using Floyd's Tortoise and Hare algorithm — O(n) time, O(1) space, no extra memory allocation.

## Prototype

```c
int check_cycle(listint_t *list);
```

## Return Value

- `0` — no cycle
- `1` — cycle detected

## Requirements

- Compiled on Ubuntu 14.04 LTS with `gcc 4.8.4` flags: `-Wall -Werror -Wextra -pedantic`
- Betty style compliant
- No global variables
- No more than 5 functions per file
- Only allowed functions: `write`, `printf`, `putchar`, `puts`, `malloc`, `free`

## Usage

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
./cycle
```

## Files

| File | Description |
|---|---|
| `0-check_cycle.c` | Function to detect a cycle in a linked list |
| `lists.h` | Header file with prototypes and struct definition |

## Repository

- **GitHub**: `holbertonschool-interview`
- **Directory**: `linked_list_cycle`