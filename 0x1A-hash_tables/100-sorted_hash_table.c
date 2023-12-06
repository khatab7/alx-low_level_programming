#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: Size of hash table
 * Return: Newly created hash table, or NULL if error
 */
shash_table_t	*shash_table_create(unsigned long int size)
{
	shash_table_t	*ptr;

	if (size == 0)
		return (NULL);
	ptr = (shash_table_t *)calloc(sizeof(*ptr), 1);
	if (!ptr)
		return (NULL);
	ptr->array = (shash_node_t **)calloc(sizeof(*(ptr->array)), size);
	if (!ptr->array)
	{
		free(ptr);
		return (NULL);
	}
	ptr->size = size;
	return (ptr);
}

/**
 * add_shash_node2 - Adds new node to sorted hash table
 * - Continuation of add_sash_node()
 *
 * @ht: Hash table
 * @key: Key of new node
 * @node: New node
 */
void	add_shash_node2(shash_table_t *ht, char *key, shash_node_t *node)
{
	shash_node_t	*ptr;

	ptr = ht->shead;
	while (ptr->snext)
	{
		if (strcmp(ptr->snext->key, key) >= 0)
		{
			node->snext = ptr->snext;
			node->sprev = ptr;
			ptr->snext->sprev = node;
			ptr->snext = node;
			break;
		}
		ptr = ptr->snext;
	}
}

/**
 * add_shash_node - Adds new node to sorted hash table
 *
 * @ht: Hash table
 * @key: Key of new node
 * @value: Value of new node
 * @index: Index in hash table
 * Return: Pointer to new node
 */
shash_node_t	*add_shash_node(shash_table_t *ht, char *key, char *value,
				unsigned long index)
{
	shash_node_t	*node;

	node = (shash_node_t *)calloc(sizeof(*node), 1);
	if (!node)
		return (NULL);
	node->next = ht->array[index];
	ht->array[index] = node;
	node->key = key;
	node->value = value;
	if (!ht->shead || strcmp(ht->shead->key, key) >= 0)
	{
		if (ht->shead)
			ht->shead->sprev = node;
		node->snext = ht->shead;
		ht->shead = node;
	}
	else if (ht->stail && strcmp(ht->stail->key, key) < 0)
	{
		ht->stail->snext = node;
		node->sprev = ht->stail;
		ht->stail = node;
	}
	else
		add_shash_node2(ht, key, node);
	if (!ht->stail)
		ht->stail = ht->shead;
	return (node);
}

/**
 * shash_table_set - Set a new value into a sorted hash table
 *
 * @ht: Hash table
 * @key: Key of new value
 * @value: New value to add
 * Return: 1 on success, 0 on error
 */
int				shash_table_set(shash_table_t *ht, const char *key,
				const char *value)
{
	unsigned long	index;
	shash_node_t	*node;
	char			*key_dup, *val_dup = NULL;

	if (!ht || !key || !*key || !ht->size || !ht->array)
		return (0);
	if (value)
		val_dup = strdup(value);
	if (value && !val_dup)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node)
	{
		if ((!value && !node->value) || !strcmp(key, node->key))
		{
			if (node->value)
				free(node->value);
			node->value = val_dup;
			return (1);
		}
		node = node->next;
	}
	key_dup = strdup(key);
	if (!key_dup)
	{
		free(val_dup);
		return (0);
	}
	if (!add_shash_node(ht, key_dup, val_dup, index))
	{
		free(val_dup);
		free(key_dup);
		return (0);
	}
	return (1);
}

/**
 * shash_table_get - Gets an element from a sorted hash table by key
 * @ht: Hash table
 * @key: Key to search with
 * Return: Corresponding value, or NULL if error
 */
char	*shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t	*ptr;

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

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: Hash table
 */
void	shash_table_print(const shash_table_t *ht)
{
	shash_node_t	*ptr;
	int				i = 0;

	if (!ht)
		return;
	ptr = ht->shead;
	printf("{");
	while (ptr)
	{
		if (i)
			printf(", ");
		i = 1;
		printf("'%s': '%s'", ptr->key, ptr->value);
		ptr = ptr->snext;
	}
	printf("}\n");
}


/**
 * shash_table_print_rev - Reverse prints a sorted hash table
 * @ht: Hash table
 */
void	shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t	*ptr;
	int				i = 0;

	if (!ht)
		return;
	ptr = ht->stail;
	printf("{");
	while (ptr)
	{
		if (i)
			printf(", ");
		i = 1;
		printf("'%s': '%s'", ptr->key, ptr->value);
		ptr = ptr->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: Hash table
 */
void	shash_table_delete(shash_table_t *ht)
{
	shash_node_t	*ptr, *tmp;

	if (!ht)
		return;
	ptr = ht->shead;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->snext;
		if (tmp->key)
			free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
	if (ht->array)
		free(ht->array);
	free(ht);
}
