#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Prints a 3x3 grid
 *
 * @grid: The 3x3 grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Checks if a 3x3 grid is stable (no cell > 3)
 *
 * @grid: The 3x3 grid to check
 *
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * topple - Performs one toppling round on an unstable grid
 *
 * @grid: The 3x3 grid to topple
 */
static void topple(int grid[3][3])
{
	int i, j;
	int tmp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			tmp[i][j] = grid[i][j];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (tmp[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i > 0)
					grid[i - 1][j] += 1;
				if (i < 2)
					grid[i + 1][j] += 1;
				if (j > 0)
					grid[i][j - 1] += 1;
				if (j < 2)
					grid[i][j + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 *
 * @grid1: First 3x3 sandpile grid (modified in place, must be stable at end)
 * @grid2: Second 3x3 sandpile grid (added to grid1)
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
