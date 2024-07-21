#include <stdio.h>

/**
 * linear_search - Search for a value in an array using Linear Search
 * @array: Array
 * @size: Size of @array
 * @value: Value to search in @array
 * Return: Index of first match, or -1 if none were found
 */
int		linear_search(int *array, size_t size, int value)
{
	size_t	i;

	if (array)
		for (i = 0; i < size; i++)
		{
			printf("Value checked array[%lu] = [%d]\n", i, array[i]);
			if (array[i] == value)
				return (i);
		}
	return (-1);
}
