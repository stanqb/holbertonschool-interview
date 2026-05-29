# Linked List Palindrome

## Description

Check if a singly linked list is a palindrome in C, using O(n) time and O(1) space.

## Requirements

- Ubuntu 14.04 LTS
- GCC 4.8.4 with `-Wall -Werror -Wextra -pedantic`
- Betty coding style

## Files

| File | Description |
|------|-------------|
| `lists.h` | Header with struct and prototypes |
| `0-is_palindrome.c` | Checks if a linked list is a palindrome |

## Algorithm

1. **Find the middle** with slow/fast pointers
2. **Reverse the first half** in place while finding the middle
3. **Compare** both halves node by node

## Usage

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
./palindrome
```
