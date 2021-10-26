#include "sort.h"


/**
 * merge_sort -  merge sort function
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int mid;
	int *temp = 0;
	size_t i;

	if (size > 1)
	{
		mid = size / 2;
		merge_sort(array, mid);
		merge_sort(array + mid, size - mid);
		temp = merge(array, array + mid, mid, size - mid);
		printf("[Done]: ");
		print_array(temp, size);
		if (temp == 0)
			return;
		for (i = 0; i < size; i++)
			array[i] = temp[i];
		free(temp);
	}
}

/**
 * merge - merges two sorted arrays
 * @arrayA: first array
 * @arrayB: second array
 * @size_A: size of the first array
 * @size_B: size of the second array
 *
 * Return: the sorted array
 */
int *merge(int *arrayA, int *arrayB, int size_A, int size_B)
{
	int *temp = 0;
	int i, j, k;

	temp = malloc(sizeof(*temp) * (size_A + size_B));
	if (temp == 0)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(arrayA, size_A);
	printf("[right]: ");
	print_array(arrayB, size_B);
	while (i < size_A && j < size_B)
	{
		if (arrayA[i] < arrayB[j])
			temp[k++] = arrayA[i++];
		else
			temp[k++] = arrayB[j++];
	}
	for (; i < size_A; i++)
		temp[k++] = arrayA[i];
	for (; j < size_B; j++)
		temp[k++] = arrayB[j];
	return (temp);
}
