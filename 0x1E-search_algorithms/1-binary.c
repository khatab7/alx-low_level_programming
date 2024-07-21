#include <stdio.h>

/**
 * binary_search - Search for a value in a sorted array using Binary Search
 * @array: Array
 * @size: Size of @array
 * @value: Value to search in @array
 * Return: Index of match, or -1 if none were found
 */
int		binary_search(int *array, size_t size, int value)
{
	size_t	i;
	int		ret;

	if (!array || size == 0)
		return (-1);
	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
	i = (size - 1) / 2;
	if (array[i] > value)
		return (binary_search(array, i, value));
	else if (array[i] < value)
	{
		ret = binary_search(array + i + 1, size - i - 1, value);
		if (ret != -1)
			return (i + 1 + ret);
		return (-1);
	}
	else
		return (i);
}
