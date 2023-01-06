#include <stdio.h>

int	matrix[20][20];

// =============================================================================
// Largest product in a grid
// =============================================================================

/**
 * @brief Prints the matrix.
 * 
 */
void	print_matrix()
{
	int	i;
	int	j;

	i = -1;
	while (++i < 20)
	{
		j = -1;
		while (++j < 20)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

/**
 * @brief Converts the given array into a bidimensional array.
 * 
 * @param arr The array to be converted.
 */
void	convert_matrix(int *arr)
{
	int	i;
	int	col;
	int row;

	i = 0;
	row = 0;
	while (i < 400)
	{
		col = 0;
		while (col < 20)
		{
			matrix[row][col] = (int)arr[i];
			col++;
			i++;
		}
		row++;
	}
}

/**
 * @brief Calculates the product of 4 positions in the east direction.
 * 
 * @return int The largest product.
 */
int		calculate_east()
{
	int	i;
	int	row;
	int	col;
	int	largest;
	int	product;

	row = 0;
	largest = matrix[0][0];
	while (row < 20)
	{
		col = 0;
		while (col < 17)
		{
			i = 0;
			product = matrix[row][col];
			while (i++ < 3)
				product *= matrix[row][col + i];
			if (product > largest)
				largest = product;
			col++;
		}
		row++;
	}
	return (largest);
}

/**
 * @brief Calculates the product of 4 positions in the south direction.
 * 
 * @return int The largest product.
 */
int		calculate_south()
{
	int	i;
	int	row;
	int	col;
	int	largest;
	int	product;

	row = 0;
	largest = matrix[0][0];
	while (row < 17)
	{
		col = 0;
		while (col < 20)
		{
			i = 0;
			product = matrix[row][col];
			while (i++ < 3)
				product *= matrix[row + i][col];
			if (product > largest)
				largest = product;
			col++;
		}
		row++;
	}
	return (largest);
}

/**
 * @brief Calculates the product of 4 positions in the southeast direction.
 * 
 * @return int The largest product.
 */
int		calculate_souteast()
{
	int	row;
	int	col;
	int largest;
	int product;

	row = 0;
	largest = matrix[0][0];
	while (row < 20)
	{
		col = 0;
		while (col < 20)
		{

			if (row + 3 < 20 && col + 3 < 20)
			{
				product = matrix[row][col] * matrix[row + 1][col + 1] \
						 * matrix[row + 2][col + 2] * matrix[row + 3][col + 3];
			}
			if (product > largest)
					largest = product;
			col++;
		}
		row++;
	}
	return (largest);
}

/**
 * @brief Calculates the product of 4 positions in the southewest direction.
 * 
 * @return int The largest product.
 */
int		calculate_southwest()
{
	int	row;
	int	col;
	int	largest;
	int	product;

	row = 0;
	largest = matrix[0][0];
	while (row < 20)
	{
		col = 0;
		while (col < 20)
		{
			if (row + 3 < 20 && col - 3 >= 0)
			{
				product = matrix[row][col] * matrix[row + 1][col - 1] \
						 * matrix[row + 2][col - 2] * matrix[row + 3][col - 3];
			}
			if (product > largest)
					largest = product;
			col++;
		}
		row++;
	}
	return (largest);
}

int		main(void)
{
	int	maximum_product;
	int	arr[] = {8, 02, 22, 97, 38, 15, 00, 40, 00, 75, 04, 05, 07, 78, 52, 12, 50, 77, 91, 8,
				49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 04, 56, 62, 00,
				81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 03, 49, 13, 36, 65,
				52, 70, 95, 23, 04, 60, 11, 42, 69, 24, 68, 56, 01, 32, 56, 71, 37, 02, 36, 91,
				22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80,
				24, 47, 32, 60, 99, 03, 45, 02, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50,
				32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70,
				67, 26, 20, 68, 02, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21,
				24, 55, 58, 05, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72,
				21, 36, 23, 9, 75, 00, 76, 44, 20, 45, 35, 14, 00, 61, 33, 97, 34, 31, 33, 95,
				78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 03, 80, 04, 62, 16, 14, 9, 53, 56, 92,
				16, 39, 05, 42, 96, 35, 31, 47, 55, 58, 88, 24, 00, 17, 54, 24, 36, 29, 85, 57,
				86, 56, 00, 48, 35, 71, 89, 07, 05, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58,
				19, 80, 81, 68, 05, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 04, 89, 55, 40,
				04, 52, 8, 83, 97, 35, 99, 16, 07, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66,
				88, 36, 68, 87, 57, 62, 20, 72, 03, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69,
				04, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36,
				20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 04, 36, 16,
				20, 73, 35, 29, 78, 31, 90, 01, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 05, 54,
				01, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 01, 89, 19, 67, 48};

	convert_matrix(arr);
	// print_matrix();
	maximum_product = calculate_east();
	if (maximum_product < calculate_south())
		maximum_product = calculate_south();
	if (maximum_product < calculate_souteast())
		maximum_product = calculate_souteast();
	if (maximum_product < calculate_southwest())
		maximum_product = calculate_southwest();
	printf("The greatest product of four adjacent numbers in the same \
 direction in the 20x20 grid is |%d|\n", maximum_product);
	return (0);
}
