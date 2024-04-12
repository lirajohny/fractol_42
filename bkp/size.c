#include <stdio.h>
int main(void)
{
	for (int i = 1; i <= 640; i++)
	{
		printf("\033[0;32m0\033[0m");   // Verde
	}
	printf("\033[0;31mthis should be a new line\033[0m\n");
}
