#include "sort.h"
/**
 * quick_sort_hoare - Quick sort algorithm
 * Description: Quick sort algorithm
 * @array: Array
 * @size: Size of the array
 * Return:
 */
void quick_sort_hoare(int *array, size_t size)
{
	q_sort(array, 0, size - 1, size);
}
/**
 * q_sort - Implementation of quick sort
 * @array: Array
 * @lo: Lower index
 * @hi: Higher index
 * @size: Size of @array
 * Return:
 */
void q_sort(int *array, int lo, int hi, size_t size)
{
	int part;

	if (lo < hi)
	{
		part = partition(array, lo, hi, size);
		q_sort(array, lo, part - 1, size);
		q_sort(array, part, hi, size);
	}
}

/**
 * partition - Partition function
 * @array: Array
 * @lo: Lower index
 * @hi: Higher index
 * @size: Size of @array
 * Return: Index when we gonna make the partition
 */
size_t partition(int *array, int lo, int hi, size_t size)
{
	int i = lo - 1;
	int j = hi + 1;
	int temp;
	int pivot = array[hi];

	while (i < j)
	{
		do
			i++;
		while (*(array + i) < pivot);
		do
			j--;
		while (*(array + j) > pivot);
		if (i < j)
		{
			temp = *(array + i);
			*(array + i) = *(array + j);
			*(array + j) = temp;
			print_array(array, size);
		}
	}
	return (i);
}
