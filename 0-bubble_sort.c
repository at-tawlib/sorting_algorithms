#include "sort.h"


/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: NULL
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size, j = 0;

	if (array == NULL || size < 2)
		return;

	while (j < size)
	{
		for (i = 0; i < len; i++)
		{
			if (array[i] > array[i + 1] && i != (len - 1))
			{
				swap(array + i, array + (i + 1));
				print_array(array, size);
			}
		}
		len--;
		j++;
	}
}

/**
 * swap - swap two elements of an array
 * @first: first element to swap
 * @second: second element to swap
 */
void swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
