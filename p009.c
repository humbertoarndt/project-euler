#include <stdio.h>

// =============================================================================
// Special Pythagorean triplet
// =============================================================================

// explanation:
// b = a;
// 	if a, b (a <= b) and c are the Pythagorean triplet,
// 	then b, a (b >= a) and c - also the solution, so we can search only one case
// c = 1000 - a - b;
// 	It's one of the conditions of the problem (we don't need to scan all possible 
// 	'c': just calculate it)

int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	sum;

	sum = 1000;
	a = 1;
	while (a <= sum / 3)
	{
		b = a + 1;
		while (b <= sum / 2)
		{
			c = sum - a - b;
			if ((a * a) + (b * b) == c * c)
				{
					printf("a: |%d|, b: |%d|, c: |%d|\n", a, b ,c);
					printf("The product of abc is: |%d|\n", (a * b) * c);
					break ;
				}
				
			b++;
		}
		a++;
	}
	return (0);
}
