#include "sort.h"

void radix_sort(int *array, size_t size);
int get_max(int *array, int size);
void radix_count(int *array, size_t size, int sign, int *buffer);

/**
 * radix_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, sign, *buffer;

	if (array == NULL || size < 2)
		return;
	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max = get_max(array, size);
	for (sign = 1; max / sign > 0; sign *= 10)
	{
		radix_count(array, size, sign, buffer);
		print_array(array, size);
	}
	free(buffer);
}

/**
 * get_max - Get the maximum value in an array of integers.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, index;

	for (max = array[0], index = 1; index < size; index++)
	{
		if (array[index] > max)
			max = array[index];
	}

	return (max);
}

/**
 * radix_count - Sort the significant digit.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @sign: The significant digit to be sorted.
 * @buffer: A buffer to store the sorted array.
 */
void radix_count(int *array, size_t size, int sign, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t indx;

	for (indx = 0; indx < size; indx++)
		count[(array[indx] / sign) % 10] += 1;
	for (indx = 0; indx < 10; indx++)
		count[indx] += count[indx - 1];
	for (indx = size - 1; (int)indx >= 0; indx--)
	{
		buffer[count[(array[indx] / sign) % 10] - 1] = array[indx];
		count[(array[indx] / sign) % 10] -= 1;
	}
	for (indx = 0; indx < size; indx++)
		array[indx] = buffer[indx];
}
