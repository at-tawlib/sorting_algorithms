#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using Selection sort algorithm
 *
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
				min = array + j;
		}
		if ((array + i) != min)
		{
			swap_int(array + i, min);
			print_array(array, size);
		}
	}
}


/**
 * swap_int - swap two elements of an array
 * @first: first element to swap
 * @second: second element to swap
 */
void swap_int(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
