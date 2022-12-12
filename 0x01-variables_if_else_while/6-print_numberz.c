#include <stdio.h>
/**
 * main - Entry
 * Description: print all single digit of base 10
 *start from 0, follow by new line
 *Return: 0
 */
int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
		putchar(num + '0');
	putchar('\n');
	return (0);
}
