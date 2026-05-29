# Palindrome Integer

## Description

Check whether an unsigned long integer is a palindrome, without dynamic memory allocation.

## Requirements

- Ubuntu 14.04 LTS
- GCC 4.8.4 with `-Wall -Werror -Wextra -pedantic`
- Betty coding style

## Files

| File | Description |
|------|-------------|
| `palindrome.h` | Header with the function prototype |
| `0-is_palindrome.c` | Checks if an unsigned long is a palindrome |

## Algorithm

Reverse the digits of `n` mathematically, then compare with the original. No strings, no arrays, no malloc.

## Usage

```bash
gcc -Wall -Wextra -Werror -pedantic -o palindrome 0-main.c 0-is_palindrome.c
./palindrome 121    # palindrome
./palindrome 112    # not a palindrome
```
