# Menger Sponge

## Description

Draws a 2D Menger Sponge of a given level using `#` characters.

## Requirements

- Ubuntu 14.04 LTS
- GCC 4.8.4 with `-Wall -Werror -Wextra -pedantic`
- Betty coding style
- Math library (`-lm`)

## Files

| File | Description |
|------|-------------|
| `menger.h` | Header with the function prototype |
| `0-menger.c` | Draws a 2D Menger sponge |

## Algorithm

A cell at `(row, col)` is a **hole** if, at any level of the base-3 decomposition, both `row % 3 == 1` and `col % 3 == 1` simultaneously. Otherwise it prints `#`.

Size of level N = `3^N`.

## Usage

```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
./0-menger 2
```
