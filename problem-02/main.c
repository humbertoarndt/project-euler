#include <stdio.h>

// =============================================================================
// Even Fibonacci numbers
// =============================================================================

/**
 * Starting by 1 and 2, the program follows the Fibonacci sequence to find the
 * sum of the even-valued terms not exceedind 4000000.
 */
int	main(void)
{
	int	i;
	int	j;
	int	temp;
	int	max;
	int	sum;

	i = 1;
	j = 2;
	sum = 2;
	max = 4000000;
	while (j < max)
	{
		temp = i + j;
		if (temp % 2 == 0)
			sum += temp;
		i = j;
		j = temp;
	}
	printf("The sum is:\t|%d|.\n", sum);
	return (0);
}
