#include "sort.h"
/**
 * bubble_sort - Sort an array of integers
 *
 * @array: An array of integers
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t index, len = size;
	bool bubble = false;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (index = 0; index < len - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				tmp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = tmp;
				print_array(array, size);
				bubble = false;
			}
		}
		len--;
	}
}
