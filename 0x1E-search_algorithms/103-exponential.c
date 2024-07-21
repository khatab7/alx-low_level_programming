#include <stdio.h>

/**
 * my_bsearch - Search for a value in a sorted array using Binary Search
 * @array: Array
 * @low: low index of search algorithm
 * @high: high index of search algorithm
 * @value: Value to search in @array
 * Return: Index of match, or -1 if none were found
 */
static int		my_bsearch(int *array, size_t low, size_t high, int value)
{
	size_t	i;

	if (!array || low > high)
		return (-1);
	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		if (i != low)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
	i = low + (high - low) / 2;
	if (array[i] > value)
		return (my_bsearch(array, low, i - 1, value));
	else if (array[i] < value)
		return (my_bsearch(array, i + 1, high, value));
	else
		return (i);
}

/**
 * exponential_search - Search in a sorted array using Exponential Search
 * @array: Array
 * @size: Size of @array
 * @value: Value to search in @array
 * Return: Index of match, or -1 if none were found
 */
int	exponential_search(int *array, size_t size, int value)
{
	size_t	i;

	if (!array || !size)
		return (-1);

	i = 1;
	while (i < size && array[i] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		i *= 2;
	}
	size = (size - 1) < i ? size - 1 : i;
	printf("Value found between indexes [%lu] and [%lu]\n", i / 2, size);
	return (my_bsearch(array, i / 2, size, value));
}
