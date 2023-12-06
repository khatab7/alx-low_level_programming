#include "hash_tables.h"

/**
 * key_index - Gets index for a given key in a hash table of a given size
 * @key: Key to get index of
 * @size: Size of hash table
 * Return: Index in hash table
 */
unsigned long int	key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
