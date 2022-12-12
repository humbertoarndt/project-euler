#include <stdio.h>
#include <math.h>

// =============================================================================
// Largest prime factor
// =============================================================================

// What is the largest prime factor of the number 600851475143 ?
// https://www.geeksforgeeks.org/prime-factor/
int main(void)
{
	int		i;
	long	gap;

	gap = 600851475143;
	while (gap % 2 == 0)
	{
		printf("|%d| ", 2);
		gap /= 2;
	}
	i = 3;
	while (i < sqrt(gap))
	{
		while (gap % i == 0)
		{
			printf("|%d| ", i);
			gap /= i;
		}
		i += 2;
	}
	if (gap > 2)
		printf("|%ld| ", gap);
	return (0);
}
