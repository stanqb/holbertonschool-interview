# Slide Line

## Description

Reproduces the 2048 game mechanics on a single horizontal line. Slides and merges an array of integers left or right: identical contiguous values (or separated by zeros) are merged.

## Requirements

- Ubuntu 14.04 LTS
- GCC 4.8.4 with `-Wall -Werror -Wextra -pedantic`
- Betty coding style

## Files

| File | Description |
|------|-------------|
| `slide_line.h` | Header with macros and prototype |
| `0-slide_line.c` | Slides and merges a line left or right |

## Algorithm

**Slide left:** iterate left to right, skip zeros, merge equal adjacent values (once per pair), pack results from index 0, fill remainder with zeros.

**Slide right:** same logic mirrored, iterating right to left.

## Usage

```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c
./0-slide_line L 2 2 0 0      # Line: 4, 0, 0, 0
./0-slide_line R 2 2 2 2      # Line: 0, 0, 4, 4
```
