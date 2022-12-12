#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 * main - Entry
 * Description: print all single digit of base 10
 *start from 0, follow by new line
 *Return: 0
 */
int main(void)
{
	char la = 'z';

	while (la >= 'a')
	{
		putchar(la);
		la--;
	}
	putchar('\n');
	return (0);
}
