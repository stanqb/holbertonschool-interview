# Sandpiles

## Description

Implementation of the sandpile model in C. A sandpile is a 3x3 grid where each cell contains a number of grains. It is **stable** when no cell contains more than 3 grains. When unstable, cells with more than 3 grains **topple**: they lose 4 grains and each orthogonal neighbor gains 1.

## Requirements

- Ubuntu 14.04 LTS
- GCC 4.8.4 with `-Wall -Werror -Wextra -pedantic`
- Betty coding style

## Files

| File | Description |
|------|-------------|
| `sandpiles.h` | Header with the function prototype |
| `0-sandpiles.c` | Computes the sum of two sandpiles |

## Algorithm

1. Add `grid2` into `grid1` cell by cell
2. While `grid1` is unstable: print it, then topple all unstable cells simultaneously
3. Toppling: a cell with > 3 grains loses 4, each orthogonal neighbor gains 1

## Usage

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
./0-sandpiles
```
