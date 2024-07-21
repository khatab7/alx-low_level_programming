#include <stdio.h>
#include <math.h>

/**
 * jump_search - Search for a value in a sorted array using jump Search
 * @array: Array
 * @size: Size of @array
 * @value: Value to search in @array
 * Return: Index of match, or -1 if none were found
 */
int		jump_search(int *array, size_t size, int value)
{
	size_t	right, left = 0;
	size_t	jump;

	jump = sqrt(size);
	if (!size || !array)
		return (-1);
	right = 0;
	while (right < size && array[right] < value)
	{
		left = right;
		right = right + jump;
		printf("Value checked array[%lu] = [%d]\n", left, array[left]);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", left, right);
	while (left <= right && left < size)
	{
		printf("Value checked array[%lu] = [%d]\n", left, array[left]);
		if (array[left] == value)
			return (left);
		left++;
	}
	return (-1);
}
