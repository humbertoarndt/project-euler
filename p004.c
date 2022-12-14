#include <stdio.h>

// =============================================================================
// Largest palindrome product
// =============================================================================

// https://www.geeksforgeeks.org/write-a-program-to-reverse-digits-of-a-number/
int	get_reverse_n(int	n)
{
	int	rev_n;

	rev_n = 0;
	while (n > 0)
	{
		rev_n = rev_n * 10 + n % 10;
		n = n / 10;
	}
	return (rev_n);
}

int	main(void)
{
	int	i;
	int	j;
	int	max;
	int	product;

	i = 99;
	max = 0;
	while (++i < 1000)
	{
		j = 99;
		while (++j < 1000)
		{
			product = i * j;
			if (product == get_reverse_n(product) && product > max)
				max = product;
		}
	}
	printf("The largest palindrome made from the product \
of two 3-digit numbers is |%d|\n", max);
	return (0);
}
