#include <stdio.h>

// =============================================================================
// Highly divisible triangular number
// =============================================================================

int	check_divisors(int triangle)
{
	int	i;
	int	count;
	int	divisor;

	i = 1;
	divisor = 0;
	count = triangle;
	while (count)
	{
		if (triangle % i == 0)
			divisor++;
		count--;
		i++;
	}
	return (divisor);
}

int	main(void)
{
	int	nb;
	int	pos;
	int	triangle;

	nb = 1;
	pos = -1;
	while (1)
	{
		triangle = (nb * (nb + 1)) / 2;
		if (check_divisors(triangle) > 500)
			break ;
		nb++;
	}
	
	printf("The value of the first triangle number to have over five hundred divisors is: |%d|\n", triangle);
	return (0);
}