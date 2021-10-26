#include "sort.h"

/**
 * selection_sort - selection sort function
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int least, mark, temp, flag = 0;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		least = array[i];
		mark = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < least)
			{
				least = array[j];
				mark = j;
				flag = 1;
			}
		}
		if (flag)
		{
			temp = array[i];
			array[i] = least;
			array[mark] = temp;
			print_array(array, size);
			flag = 0;
		}
	}
}
