#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
* main - Entry
* Description:get a random number and print it
*if it positive , negative, or zero
*Return: 0
*/
int main(void)
{
int n;
scand(time(0));
n = rand() - RAND_MAX / 2;
if (n > 0)
printf("%i is positive\n", n);
else if (n<0)
printf("%i is nagative\n", n);
else
printf("%i is zero\n", n);
return (0);
}
