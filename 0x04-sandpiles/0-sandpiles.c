#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"


/**
 * print_grid2 - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid2(int grid[3][3])
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
 * simple_sum - creates the sum of 2 sandpiles
 * @grid1: first grid
 * @grid2: second gris
 * Return: Void
 */
void simple_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}
}


/**
 * isunstable - test if a grid is unstable
 * @grid1: first grid
 * Return: 0 if stable, 1 if unstable
 */
int isunstable(int grid1[3][3])
{
	int i, j;
	int x = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				x = 1;
		}
	}
	return (x);
}

/**
 * stabilize - stabilize an unstable grid
 * @grid1: grid to stabilize
 * @grid2: auxiliary grid
 * Return: Void
 */
void stabilize(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid2[i][j] = 0;
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i - 1 >= 0)
					grid2[i - 1][j] += 1;
				if (i + 1 < 3)
					grid2[i + 1][j] += 1;
				if (j - 1 >= 0)
					grid2[i][j - 1] += 1;
				if (j + 1 < 3)
					grid2[i][j + 1] += 1;
			}
		}
	}
	simple_sum(grid1, grid2);
}





/**
 * sandpiles_sum - creates the sum of 2 sandpiles
 * @grid1: first grid
 * @grid2: second gris
 * Return: Void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable;

	simple_sum(grid1, grid2);
	unstable = isunstable(grid1);

	while (unstable)
	{
		printf("=\n");
		print_grid2(grid1);
		stabilize(grid1, grid2);
		unstable = isunstable(grid1);
	}
}
