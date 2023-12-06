#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @hash: Hash table
 */
void	hash_table_delete(hash_table_t *hash)
{
	hash_node_t	*ptr, *tmp;
	unsigned long	i;

	if (!hash || !hash->size || !hash->array)
		return;
	for (i = 0; i < hash->size; i++)
	{
		ptr = hash->array[i];
		while (ptr)
		{
			tmp = ptr;
			ptr = ptr->next;
			if (tmp)
			{
				if (tmp->key)
					free(tmp->key);
				if (tmp->value)
					free(tmp->value);
				free(tmp);
			}
		}
	}
	free(hash->array);
	free(hash);
}
