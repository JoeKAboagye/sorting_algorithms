#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

#define SIDE1(i) ((2 * i) + 1)
#define SIDE2(i) ((2 * i) + 2)
#define PARENT(i) ((i - 1) / 2)

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/*print functions*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*functions for algorithms*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);

/*helpers*/
void back(int *array, int a, int b, size_t size);
void swap_nodes(listint_t *first, listint_t *second);
void swap_link(listint_t *first, listint_t *second, listint_t **head);
void swaper(int a, int b, int *array);
void back(int *array, int a, int b, size_t size);
int partition(int *array, size_t low, size_t hi, size_t size);
void heap(int *array, size_t size, size_t original_s);
int *merge(int *arrayA, int *arrayB, int size_A, int size_B);

#endif /*SORT_H*/
