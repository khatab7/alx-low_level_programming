#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry
 * Description: print all single digit of base 10
 * start from 0, follow by new line
 * Return: 0
 */
int main(void)
{
	char n;
	char la;

	for (n = 0; n < 10; n++)
		putchar((n % 10) + '0');
	for (la = 'a'; la <= 'f'; la++)
		putchar(la);
	putchar('\n');
	return (0);
}
