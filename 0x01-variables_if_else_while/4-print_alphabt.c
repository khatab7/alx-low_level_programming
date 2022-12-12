#include <stdio.h>
/**
 * main - Entry
 * Description: a random number check
 *Return: 0
 */
int main(void)
{
	char la = 'a';

	while (la <= 'z')
	{
		if (la != 'e' && la != 'q')
		{
			putchar(la);
		}
		la++;
	}
	putchar('\n');
	return (0);
}
