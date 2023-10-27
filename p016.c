// =============================================================================
// Power Digit Sum
// =============================================================================

// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

// What is the sum of the digits of the number 2^1000?

// =============================================================================
// Includes
// =============================================================================

#include <stdio.h>

// =============================================================================
// Defines
// =============================================================================

#define BASE 2
#define MAXDIGITS 500
#define EXPONENT 1000

// =============================================================================
// Functions
// =============================================================================

/**
 * @brief Caculates a exponetial value for a number.
 * 
 * @param base The base number.
 * @param exponent The exponent to multiply for.
 * @return int The result.
 */
int	power(int base, int exponent)
{
	int	nb;

	nb = base;
	for (int i = 1; i < exponent; i++)
		nb*= base;
	return (nb);
}

/**
 * @brief Caculate the sum of the digits in a number.
 * 
 * @param nb The number to sum its digits.
 * @return int The sum of digits.
 */
int	sum_digits(int nb)
{
	int	sum;

	sum = 0;
	while (nb != 0)
	{
		sum += nb % 10;
		nb /= 10;
	}
	return (sum);
}

/**
 * @brief Populates an array where each position is a digit from an exponential
 * operation
 * 
 * @param arr The array to store the digits.
 */
void	populate_arr(int *arr)
{
	int	carry;
	int	temp;

	arr[0] = 1;
	for (int i =0; i < EXPONENT; i++)
	{
		carry = 0;
		for (int j = 0; j < MAXDIGITS; j++)
		{
			temp = BASE * arr[j] + carry;
			carry = 0;

			/* If greater than 9, calculate each digit to store. */
			if (temp > 9)
			{
				arr[j] = temp % 10;
				carry = temp / 10;
			}
			else
				arr[j] = temp;
		}
	}

	return ;
}

int	main(void)
{
	// ========================================================================
	// Undertanding the problem
	// ========================================================================

	int	p;
	int	sum;
	
	p = power(BASE, 15);
	sum = sum_digits(p);

	printf("%d^%d = %d and the sum of its digits is %d\n", BASE, 15, power(BASE, 15), sum);

	// ========================================================================
	// Resolving the problem
	// ========================================================================

	int	l_nb[MAXDIGITS] = {0};

	populate_arr(l_nb);

	sum = 0;
	for (int i = MAXDIGITS - 1; i >= 0; i--)
		sum += l_nb[i];
	
	printf("The sum of the digits of the number %d^%d is:\t%d\n", BASE, EXPONENT, sum);

	return (0);
}
