#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * Format: {<key1>: <value1>, <key2>, <value2>}
 * @ht: Hash table
 */
void	hash_table_print(const hash_table_t *ht)
{
	unsigned long	i, j = 0;
	hash_node_t		*ptr;

	if (!ht)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		ptr = ht->array[i];
		while (ptr)
		{
			if (j)
				printf(", ");
			printf("'%s': '%s'", ptr->key, ptr->value);
			ptr = ptr->next;
			j = 1;
		}
	}
	printf("}\n");
}
