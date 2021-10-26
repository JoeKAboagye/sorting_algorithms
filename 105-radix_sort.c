#include "sort.h"
/**
 * radix_sort - radix sort function
 * Description: radix sort algorithm test
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	unsigned int j;
	int p, max, i;
	int *temp;

	max = 0;
	if (array == NULL || size < 2)
		return;
	for (j = 0; j < size; j++)
	{
		if (*(array + j) > max)
			max = *(array + j);
	}
	for (p = 1; max / p > 0; p *= 10)
	{
	int index[10] = {0};

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	for (i = 0; i < (int) size; i++)
		index[(*(array + i) / p) % 10]++;
	for (i = 1; i < 10; i++)
		index[i] += index[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		temp[index[(*(array + i) / p) % 10] - 1] = *(array + i);
		index[(*(array + i) / p) % 10]--;
	}
	for (i = 0; i < (int) size; i++)
		*(array + i) = temp[i];
	free(temp);
	print_array(array, size);
	}
}
