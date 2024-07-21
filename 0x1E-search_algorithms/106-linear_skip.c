#include "search_algos.h"
#include <math.h>
#include <stdio.h>

/**
 * linear_skip - Performs Linear skip on a linked list
 * @list: Linked list
 * @value: Key to search for
 * Return: Pointer to matching node, or NULL if not found
 */
skiplist_t	*linear_skip(skiplist_t *list, int value)
{
	skiplist_t	*high;

	if (!list)
		return (NULL);
	high = list->express;
	if (high)
		printf("Value checked at index [%lu] = [%d]\n", high->index, high->n);
	while (high && high->n < value && high->next)
	{
		list = high;
		high = high->express;
		if (!high)
		{
			high = list;
			while (high && high->next)
				high = high->next;
		}
		else
			printf("Value checked at index [%lu] = [%d]\n", high->index, high->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", list->index,
		high->index);
	while (list && list->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		list = list->next;
		if (!list || list->index > high->index)
			return (NULL);
	}
	if (list && list->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		return (list);
	}
	return (NULL);
}
