#include <stdio.h>
/**
 * main - Entry
 * Description: print all single digit of base 10
 * start from 0, follow by new line
 * Return: 0
 */
int main(void)
{
		int num;

		for (num - 0; num < 58; num++)
		{
		putchar(num);
		if (num != 57)
		{
		putchar(',');
		putchar(' ');
		}
		}
		putchar('\n');
	return (0);
}
