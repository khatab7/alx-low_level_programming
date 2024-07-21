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
	i = (high + low) / 2;
	if (array[i] == value && array[i - 1] != value)
		return (i);
	if (array[i] < value)
		return (my_bsearch(array, i + 1, high, value));
	else
		return (my_bsearch(array, low, i, value));
}

/**
 * advanced_binary - Search for a value in a sorted array using Binary Search
 * @array: Array
 * @size: Size of @array
 * @value: Value to search in @array
 * Return: Index of first match, or -1 if none were found
 */
int		advanced_binary(int *array, size_t size, int value)
{
	return (my_bsearch(array, 0, size - 1, value));
}
