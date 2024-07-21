#include <stdio.h>

/**
 * interpolation_search_recurs - Search value using interpolation Search
 * @array: Array
 * @left: left index of search algorithm
 * @right: right index of search algorithm
 * @value: Value to search in @array
 * Return: Index of match, or -1 if none were found
 */
int		interpolation_search_recurs(int *array, size_t left, size_t right,
									int value)
{
	size_t	i;

	i = left + ((value - array[left]) * (right - left)
		/ (array[right] - array[left]));
	if (i > right)
	{
		printf("Value checked array[%lu] is out of range\n", i);
		return (-1);
	}
	printf("Value checked array[%lu] = [%d]\n", i, array[i]);
	if (array[i] > value)
		return (interpolation_search_recurs(array, 0, i - 1, value));
	else if (array[i] < value)
		return (interpolation_search_recurs(array, i + 1, right, value));
	else
		return (i);
}


/**
 * interpolation_search - Search value using interpolation Search
 * @array: Array
 * @size: Size of @array
 * @value: Value to search in @array
 * Return: Index of match, or -1 if none were found
 */
int		interpolation_search(int *array, size_t size, int value)
{
	if (!array || !size)
		return (-1);
	return (interpolation_search_recurs(array, 0, size - 1, value));
}
