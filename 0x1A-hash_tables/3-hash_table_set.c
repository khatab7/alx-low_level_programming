#include "hash_tables.h"

/**
 * add_hash_node - Adds value to hash list
 * @list: Linked list
 * @key: Key of new node
 * @value: Value of new node
 * Return: Pointer to new node
 */
hash_node_t	*add_hash_node(hash_node_t **list, char *key, char *value)
{
	hash_node_t	*ptr;

	if (!list)
		return (NULL);
	ptr = (hash_node_t *)malloc(sizeof(*ptr));
	ptr->key = key;
	ptr->value = value;
	ptr->next = *list;
	*list = ptr;
	return (ptr);
}

/**
 * hash_table_set - Adds a value to a hash table
 * @ht: Hash table
 * @key: Key of value to add
 * @value: Value to add
 * Return: 1 if Success, else 0
 */
int		hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	int			index;
	char		*key_dup;
	char		*value_dup;
	hash_node_t	*ptr;

	if (!key || !*key || !ht || !ht->size || !ht->array)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	value_dup = strdup(value);
	if (!value_dup)
		return (0);
	ptr = ht->array[index];
	while (ptr)
	{
		if (!strcmp(key, ptr->key))
		{
			if (ptr->value)
				free(ptr->value);
			ptr->value = value_dup;
			return (1);
		}
		ptr = ptr->next;
	}
	key_dup = strdup(key);
	if (key && !key_dup)
	{
		free(value_dup);
		return (0);
	}
	if (!add_hash_node(&ht->array[index], key_dup, value_dup))
	{
		free(value_dup);
		free(key_dup);
		return (0);
	}
	return (1);
}
