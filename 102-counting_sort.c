#include "sort.h"

/**
 * counting_sort - implementation of counting sort
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int largest = 0;
	int *cnt = NULL, *output = NULL;
	size_t i, cnt_size;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > largest)
			largest = array[i];
	}
	cnt_size = largest + 1;
	cnt = malloc(sizeof(*cnt) * cnt_size);
	if (cnt == NULL)
		return;
	for (i = 0; i < cnt_size; i++)
		cnt[i] = 0;
	for (i = 0; i < size; i++)
		cnt[array[i]] += 1;
	for (i = 0; i < cnt_size; i++)
	{
		if (i == 0)
			continue;
		cnt[i] += cnt[i - 1];
	}
	print_array(cnt, cnt_size);
	output = malloc(sizeof(*output) * size);
	for (i = 0; i < size; i++)
		output[--cnt[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(cnt);
	free(output);
}
