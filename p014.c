#include <stdio.h>

// =============================================================================
// Longest Collatz sequence
// =============================================================================

/**
 * Tested with this caculator
 * https://www.dcode.fr/collatz-conjecture
 */

/**
 * @brief Checks if a number is even
 * 
 * @param n Number to check
 * @return int If true 0, else 1
 */
int	is_even(int n)
{
	if (n % 2 == 0)
		return (0);
	return (1);
}

/**
 * @brief Calculates the length from the Collatz sequence from a number
 * 
 * @param n The number to caculate Collatz sequence
 * @return int The lenght
 */
int	collatz(long n)
{
	int	count;

	count = 0;
	while (n > 1)
	{
		if (is_even(n) == 0)
			n /= 2;
		else
			n = (3 * n) + 1;
		count++;
	}
	return (++count);
}

int main(void)
{
	int	answer;
	long	temp;
	int	i = 1000000;
	long	largest = 0;

	while (i > 1)
	{
		temp = collatz(i);

		if (temp > largest)
		{
			largest = temp;
			answer = i;
		}
		i--;
	}
	printf("Starting number: |%d| Largest chain: |%ld|\n", answer, largest);
	return (0);
}
