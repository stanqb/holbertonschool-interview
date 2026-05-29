#include "slide_line.h"

/**
 * slide_left - Slides and merges an array to the left
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void slide_left(int *line, size_t size)
{
	size_t i, pos;
	int last_merged;

	pos = 0;
	last_merged = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;
		if (pos > 0 && line[pos - 1] == line[i] && !last_merged)
		{
			line[pos - 1] *= 2;
			last_merged = 1;
		}
		else
		{
			line[pos] = line[i];
			if (pos != i)
				line[i] = 0;
			pos++;
			last_merged = 0;
		}
	}
	while (pos < size)
		line[pos++] = 0;
}

/**
 * slide_right - Slides and merges an array to the right
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void slide_right(int *line, size_t size)
{
	int pos, last_merged;
	int i;

	pos = (int)size - 1;
	last_merged = 0;

	for (i = (int)size - 1; i >= 0; i--)
	{
		if (line[i] == 0)
			continue;
		if (pos < (int)size - 1 && line[pos + 1] == line[i] && !last_merged)
		{
			line[pos + 1] *= 2;
			last_merged = 1;
		}
		else
		{
			line[pos] = line[i];
			if (pos != i)
				line[i] = 0;
			pos--;
			last_merged = 0;
		}
	}
	while (pos >= 0)
		line[pos--] = 0;
}

/**
 * slide_line - Slides and merges an array to the left or right
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}
	if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		return (1);
	}
	return (0);
}
