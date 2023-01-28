#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 * Shell sort algorithm, using the Knuth Sequence
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_int(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
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
