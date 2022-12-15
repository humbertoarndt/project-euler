#include <stdio.h>

// =============================================================================
// Summation of primes
// =============================================================================

// Code from p007
int	is_prime(int n)
{
	int	i;

	if (n <= 1)
		return (1);
	if (n == 2 || n == 3)
		return (1);
	if (n % 2 == 0 || n % 3 == 0)
		return (1);
	i = 5;
	while (i * i <= n)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return (1);
		i = i + 6;
	}
	return (0);
}

int	main(void)
{
	int		i;
	long	sum;

	i = -1;
	sum = 5;
	while (++i <= 2000000)
	{
		if (!(is_prime(i)))
			sum += i;
	}
	printf("The sum of all the primes bellow two million is: |%ld|.\n", sum);
	return (0);
}
