#include <stdio.h>

// =============================================================================
// Sum square difference
// =============================================================================

int	sum_of_squares(int index)
{
	int	i;
	int	sum_of_sqr;

	i = 0;
	sum_of_sqr = 0;
	while (++i <= index)
	{
		sum_of_sqr += i * i;
	}
	return (sum_of_sqr);
}

int	square_of_sum(int index)
{
	int	i;
	int	sqr_of_sum;

	i = 0;
	sqr_of_sum= 0;
	while (++i <= index)
	{
		sqr_of_sum += i;
	}
	sqr_of_sum *= sqr_of_sum;
	return (sqr_of_sum);
}

int	main(void)
{
	int	sum_of_sqr;
	int	sqr_of_sum;

	sum_of_sqr = sum_of_squares(100);
	sqr_of_sum = square_of_sum(100);
	printf("The difference between the sum of the squares of the firts one \
hundred natural numbers and the square of the sum is:\
\t|%d|\n", sqr_of_sum - sum_of_sqr);
	return (0);
}
