#include <stdio.h>

// =============================================================================
// Multiples of 3 or 5
// =============================================================================

// Find the sum of all the multiples of 3 or 5 below 1000.

int	main(void)
{
	int	i;
	int	sum;

	i = -1;
	while (++i < 1000)
	{
		if(i % 3 == 0 || i % 5 == 0)
			sum += i;
	}
	printf("The sum is |%d|.\n", sum);
	return (0);
}
