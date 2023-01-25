#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}


/**
 * lomuto_sort - implement Quick sort algorithm through recursion
 *
 * @array: array to sort
 * @size: size of array
 * @left: starting index of array
 * @right: ending index of array
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}


/**
 * lomuto_partition - order a subset of an array of integers
 * according to the Lomuto partition scheme (last element as pivot)
 *
 * @array: array to sort
 * @size: size of array
 * @left: starting index of the subset to order
 * @right: ending index of the subset to order
 *
 * Return: the final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_int(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_int(array + above, pivot);
		print_array(array, size);
	}
	return (above);
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
