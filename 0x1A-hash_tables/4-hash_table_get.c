#include "hash_tables.h"

/**
 * hash_table_get - Get a value in a hash table from a key
 * @ht: Hash table
 * @key: Key to search in table
 * Return: Value corresponding to key, or NULL if error
 */
char	*hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t	*ptr;

	if (!ht || !key || !ht->array || !ht->size)
		return (NULL);
	ptr = ht->array[key_index((const unsigned char *)key, ht->size)];
	while (ptr)
	{
		if (!strcmp(key, ptr->key))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}
