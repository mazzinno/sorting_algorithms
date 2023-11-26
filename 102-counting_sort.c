#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sort, max, index;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	for (max = array[0], index = 1; index < (int)size; index++)
	{
		if (array[index] > max)
			max = array[index];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sort);
		return;
	}

	for (index = 0; index < (max + 1); index++)
		count[index] = 0;
	for (index = 0; index < (int)size; index++)
		count[array[index]] += 1;
	for (index = 0; index  < (max + 1); index++)
		count[index] += count[index - 1];

	print_array(count, max + 1);
	for (index = 0; index < (int)size; index++)
	{
		sort[count[array[index]] - 1] = array[index];
		count[array[index]] -= 1;
	}

	for (index = 0; index < (int)size; index++)
		array[index] = sort[index];

	free(sort);
	free(count);
}
