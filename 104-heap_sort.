#include "sort.h"

/**
 * heap_sort - heap sort function
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t temp_s = size;

	while (temp_s > 1)
	{
		heap(array, temp_s, size);
		swaper(0, temp_s - 1, array);
		print_array(array, size);
		temp_s--;
	}
}

/**
 * heap - builds complete heap from an array in swap
 * @array: array to be sorted
 * @size: size of the array
 * @original_s: original size of the array
 *
 * Return: void
 */
void heap(int *array, size_t size, size_t original_s)
{
	size_t i;

	for (i = (size - 1); (signed int) i >= 0 ; i--)
	{
		while (SIDE1(i) < size)
		{
			if (SIDE2(i) < size)
			{
				if (array[SIDE2(i)] > array[i] || array[SIDE1(i)] > array[i])
				{
					if (array[SIDE2(i)] >= array[SIDE1(i)])
					{
						swaper(i, SIDE2(i), array);
						i = SIDE2(i);
						print_array(array, original_s);
					}
					else
					{
						swaper(i, SIDE1(i), array);
						i = SIDE1(i);
						print_array(array, original_s);
					}
				}
				else
					break;
			}
			else
			{
				if (array[SIDE1(i)] > array[i])
				{
					swaper(i, SIDE1(i), array);
					print_array(array, original_s);
				}
				break;
			}
		}
	}
}

/**
 * swaper - swap to integers
 * @a: first integer
 * @b: secoond integer
 * @array: array
 *
 * Return: swaped integers
 */
void swaper(int a, int b, int *array)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}