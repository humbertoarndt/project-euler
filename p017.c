// -----------------------------------------------------------------------------
// Number Letter Counts
// -----------------------------------------------------------------------------

// If the numbers 1 to 5 are written out in words: one, two, three, four, five, 
// then there are 3 +3 +5 +4 +4 = 19 letters used in total.

// If all the numbers from 1 to 1000 (one thousand) inclusive were written out in 
// words, how many letters would be used?

// NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and 
// forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 
// letters. The use of "and" when writing out numbers is in compliance with British 
// usage.

// =============================================================================
// Includes
// =============================================================================

#include <stdio.h>
#include <string.h> // strlen()

// =============================================================================
// Macros
// =============================================================================

#define HUNDREDAND 10
#define ONETHOUSAND 11

// =============================================================================
// Functions
// =============================================================================

int	main(void)
{
	int		count;
	char	*units[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char	*tens[9] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char	*tenth[9] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

	count = 0;
	// 1 ~ 9
	for (int i = 0; i < 9; i++)
		count += strlen(units[i]);

	// 11 ~ 19
	for (int i = 0; i < 9; i++)
		count += strlen(tens[i]);

	// 10 && 20 ~ 99
	for (int i = 0; i < 9; i++)
	{
		count += strlen(tenth[i]);
		if (i > 0)
			for (int j = 0; j < 9; j++)
				count += (strlen(tenth[i]) + strlen(units[j]));
	}

	// x00 ~ x09
	for (int i = 0; i < 9; i++)
	{
		count += strlen(units[i]) + strlen("hundred");
		for (int j = 0; j < 9; j++)
			count += strlen(units[i]) + HUNDREDAND + strlen(units[j]);
	}

	// x11 ~ x19
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			count += strlen(units[i]) + HUNDREDAND + strlen(tens[j]);
	}

	// 12x ~ 999
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			count += strlen(units[i]) + HUNDREDAND + strlen(tenth[j]);
			if (j > 0)
				for (int k = 0; k < 9; k++)
					count += strlen(units[i]) + HUNDREDAND + strlen(tenth[j]) + strlen(units[k]);
		}
	}

	count += ONETHOUSAND;
	printf("The total letter count from number 1 to 1000 is: [%d]\n", count);
	return (0);
}
