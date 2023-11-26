#include "sort.h"

void quick_sort_hoare(int *array, size_t size);
void hoare_sort(int *array, size_t size, int left, int right);
int hoare_partition(int *array, size_t size, int left, int right);

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order.
 *
 * @array: The arrays to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}

/**
 * hoare_sort - Implement the quick sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @left: The starting index of the array.
 * @right: The ending index of the array.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * hoare_partition - Order a subset of an array of integers.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @left: The starting index of the array.
 * @right: The ending index of the array.
 *
 * Return: The final partitioning index.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below, tmp;
	int *bottom, *top;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		top = array + above;
		bottom = array + below;

		if (above < below)
		{
			tmp = *top;
			*top = *bottom;
			*bottom = tmp;

			print_array(array, size);
		}
	}

	return (above);
}
