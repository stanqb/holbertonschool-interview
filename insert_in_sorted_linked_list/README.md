# Insert in Sorted Linked List

## Description
This project implements a function that inserts a number into a sorted singly linked list while maintaining the sorted order. This is a common technical interview problem that tests understanding of linked list operations and pointer manipulation.

## Requirements
- **Allowed editors:** `vi`, `vim`, `emacs`
- **Environment:** Ubuntu 14.04 LTS
- **Compiler:** gcc 4.8.4 with flags `-Wall -Werror -Wextra -pedantic`
- **Coding style:** Betty style (checked with `betty-style.pl` and `betty-doc.pl`)
- **File requirements:**
  - All files must end with a new line
  - No global variables allowed
  - Maximum 5 functions per file
  - All header files must be include guarded

## Function Prototype
```c
listint_t *insert_node(listint_t **head, int number);
```

### Parameters
- `head`: Double pointer to the head of the sorted linked list
- `number`: Integer to be inserted in the correct position

### Returns
- Address of the new node on success
- `NULL` if insertion failed

## Data Structure
```c
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

## Algorithm
The function traverses the sorted linked list to find the correct insertion position:
1. Handle edge case of empty list or insertion at the beginning
2. Find the position where the new node should be inserted
3. Create new node and update pointers to maintain list integrity
4. Return pointer to the newly created node

## Usage Example
```c
#include "lists.h"

int main(void)
{
    listint_t *head = NULL;
    
    // Build sorted list: 0, 1, 2, 3, 4, 98, 402, 1024
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    
    // Insert 27 in correct position
    insert_node(&head, 27);
    
    // Result: 0, 1, 2, 3, 4, 27, 98, 402, 1024
    print_listint(head);
    
    free_listint(head);
    return (0);
}
```

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-insert_number.c -o insert
./insert
```

## Files
- `0-insert_number.c`: Main implementation file
- `lists.h`: Header file with function prototypes and structure definition
- `linked_lists.c`: Helper functions for list operations
- `0-main.c`: Test file (for testing purposes)

## Repository Structure
```
holbertonschool-interview/
└── insert_in_sorted_linked_list/
    ├── README.md
    ├── 0-insert_number.c
    ├── lists.h
    ├── linked_lists.c
    └── 0-main.c
```
