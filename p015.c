#include <stdio.h>

// =============================================================================
// Lattice paths
// =============================================================================

// Starting in the top left corner of a 2×2 grid, and only being able to move to 
// the right and down, there are exactly 6 routes to the bottom right corner.

// all possibilitis
// RRDD
// RDRD
// RDDR
// DRRD
// DRDR
// DDRR

// The total number of paths to the bottom right corner is equal to sum of
// paths to square above it, and to it's left.
int	main(void)
{
	int	i;
	int	j;
	unsigned long long	grid[21][21];

	// Initialize grid to all 1s
	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 21; j++)
		{
			grid[i][j] = 1;
		}
	}

	// Grid square in bottom right will be = sum of top and left squares
	for (i = 1; i < 21; i++)
	{
		for (j = 1; j < 21; j++)
			grid[i][j] = grid[i-1][j] + grid[i][j-1];
	}

	printf("The number os routes through a 20×20 grid is: |%lld|\n", grid[20][20]);
	return (0);
}
