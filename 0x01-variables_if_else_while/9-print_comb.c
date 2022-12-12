#include <stdio.h>
/**
 * main - Entry
 * Description: print all single digit of base 10
 * start from 0, follow by new line
 * Return: 0
 */
int main(void)
{
	int nun;

	for (num = 0; num <= 9; num++)
	{
		putchar(num + '0');
		if (num < 9)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
