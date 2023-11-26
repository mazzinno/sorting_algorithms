#include "sort.h"

void shell_sort(int *array, size_t size);
void swap_ints(int *a, int *b);

/**
 * shell_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, index, jndex;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap = gap / 3)
	{
		for (index = gap; index < size; index++)
		{
			jndex = index;

			while (jndex >= gap && array[jndex - gap] > array[jndex])
			{
				swap_ints(array + jndex, array + (jndex - gap));
				jndex -= gap;
			}
		}
		print_array(array, size);
	}
}

/**
 * swap_ints - Swap two integers in an array.
 *
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
