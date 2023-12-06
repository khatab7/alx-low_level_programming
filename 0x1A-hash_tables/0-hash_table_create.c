#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table array
 * @size: Size of the hash table
 * Return: Pointer to hash table
 */
hash_table_t	*hash_table_create(unsigned long int size)
{
	hash_table_t	*ptr;

	if (!size)
		return (NULL);
	ptr = (hash_table_t *)malloc(sizeof(hash_table_t));
	if (!ptr)
		return (NULL);
	ptr->array = (hash_node_t **)malloc(sizeof(hash_node_t *) * size);
	if (!ptr->array)
		return (NULL);
	ptr->size = size;
	return (ptr);
}
