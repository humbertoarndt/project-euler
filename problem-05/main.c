#include <stdio.h>

// =============================================================================
// Smallest multiple
// =============================================================================

// 2520 is the smallest number that can be divided by each of the numbers from
// 1 to 10 without any remainder.

// What is the smallest positive number that is evenly divisible by all of the
// numbers from 1 to 20?

int	main(void)
{
	int	i;
	int	rest;

	i = 1;
	while (1)
	{
		rest = i % 1;
		if (i % 2 == rest &&
			i % 3 == rest &&
			i % 4 == rest &&
			i % 5 == rest &&
			i % 6 == rest &&
			i % 7 == rest &&
			i % 8 == rest &&
			i % 9 == rest &&
			i % 10 == rest &&
			i % 11 == rest &&
			i % 12 == rest &&
			i % 13 == rest &&
			i % 14 == rest &&
			i % 15 == rest &&
			i % 16 == rest &&
			i % 17 == rest &&
			i % 18 == rest &&
			i % 19 == rest &&
			i % 20 == rest)
			break ;
		i++;
	}
	printf("The smallest positive number that is evenly \
divisible by all of the numbers from 1 to 20 is:\t|%d|\n", i);
}
