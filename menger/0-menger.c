#include <math.h>
#include <stdio.h>
#include "menger.h"

/**
 * is_hole - Checks if a position (row, col) is a hole in the Menger sponge
 *
 * @row: Row index
 * @col: Column index
 *
 * Return: 1 if it is a hole, 0 otherwise
 */
static int is_hole(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row /= 3;
		col /= 3;
	}
	return (0);
}

/**
 * menger - Draws a 2D Menger sponge of the given level
 *
 * @level: Level of the Menger sponge to draw
 */
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = (int)pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_hole(row, col))
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}
