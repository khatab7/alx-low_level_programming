#include <stdio.h>
/**
 * main - Entry
 * and then in uppercase, follow by anew line
 * Return: 0
 */
int main(void)
{
	char lt = 'a';

	while (lt <= 'z')
	{
		putchar(lt);
		lt++;
	}
	lt = 'A';
	while (lt <= 'Z')
	{
		putchar(lt);
		lt++;
	}
	putchar('\n');
	return (0);
}
