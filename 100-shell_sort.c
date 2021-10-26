#include "sort.h"

/**
 * shell_sort - implementation of shell_sort
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int temp;

	while (interval < size)
		interval = interval * 3 + 1;

	while (interval)
	{
		for (i = interval; i < size; i += 1)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
				array[j] = array[j - interval];
			array[j] = temp;
		}
		if (interval < size)
			print_array(array, size);
		interval /= 3;
	}
}
