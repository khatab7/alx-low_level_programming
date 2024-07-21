#include "search_algos.h"
#include <math.h>
#include <stdio.h>


/**
 * jump_pointer - Returns nth element in linked list
 * @ptr: Pointer to linked list
 * @jump: Pointer to int. Corresponds to position to jump to.
 * Return: Pointer to nth element.
 */
listint_t	*jump_pointer(listint_t *ptr, size_t jump)
{
	while (ptr && ptr->next && jump)
	{
		jump--;
		ptr = ptr->next;
	}
	return (ptr);
}


/**
 * jump_list - Performs Jump Search on a linked list
 * @list: Linked list
 * @size: Size of list
 * @value: Key to search for
 * Return: Pointer to matching node, or NULL if not found
 */
listint_t	*jump_list(listint_t *list, size_t size, int value)
{
	size_t		jump;
	listint_t	*high;

	jump = sqrt(size);
	if (!size || !list)
		return (NULL);
	high = jump_pointer(list, jump);
	if (high)
		printf("Value checked at index [%lu] = [%d]\n", high->index, high->n);
	while (high && high->n < value && high->next)
	{
		list = high;
		high = jump_pointer(list, jump);
		if (high)
			printf("Value checked at index [%lu] = [%d]\n", high->index, high->n);
		if (list->index >= size - 1)
			break;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", list->index,
		high->index);
	while (list && list->index < size && list->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		list = list->next;
		if (!list || list->index > high->index)
			return (NULL);
	}
	if (list && list->index < size && list->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		return (list);
	}
	return (NULL);
}
