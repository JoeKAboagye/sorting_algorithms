#include "sort.h"

/**
 * insertion_sort_list - an implementation of insertion sort
 * @list: doubly linked list to be sorted
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr = NULL, *ptr2 = NULL;
	int a, b;

	if (list == NULL)
		return;
	if ((*list)->next == NULL)
		return;

	ptr = *list;
	while (ptr != NULL)
	{
		if (ptr->prev != NULL)
		{
			ptr2 = ptr;
			ptr = ptr->next;
			while (ptr2->prev != NULL)
			{
				a = (ptr2->prev)->n;
				b = ptr2->n;
				if (a <= b)
					break;
				swap_nodes(ptr2->prev, ptr2);
				if (ptr2->prev == NULL)
					*list = ptr2;
				print_list(*list);
			}
		}
		else
			ptr = ptr->next;
	}
}

/**
 * swap_nodes - swaps adjacent nodes of a doubly linked list
 * @x: first node
 * @y: second node
 *
 * Return: nothing
 */
void swap_nodes(listint_t *x, listint_t *y)
{
	if (x->prev != NULL)
		(x->prev)->next = y;
	if (y->next != NULL)
		(y->next)->prev = x;
	y->prev = x->prev;
	x->prev = y;
	x->next = y->next;
	y->next = x;
}
