#include <stdio.h>

// =============================================================================
// 10001st prime
// =============================================================================

/**
 * @brief Checks if a number is prime.
 * 
 * @param n The number to be checked.
 * @return int If n is prime return 0, if not returns 1.
 */
// https://www.geeksforgeeks.org/prime-numbers/
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
	int	i;
	int	prime;

	i = -1;
	prime = 2;
	while (1)
	{
		if (!is_prime(i))
			prime++;
		if(prime == 10001)
			break ;
		i++;
	}
	printf("The 10001st prime number is |%d|\n", i);
	return (0);
}
