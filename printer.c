#include "header.h"
#include <stdio.h>

int	printer(int sizeAg, t_size *size, int *a, int *b)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (sizeAg--)
	{
		if (i < size->sizea)
		{
			printf("%d | %d", a[i], size->fic_a[i]);
			i++;
		}
		else
			printf("- | -");
		printf(" || ");
		if (l < size->sizeb)
		{
			printf("%d | %d", b[l], size->fic_b[l]);
			l++;
		}
		else
			printf("- | -");
		printf("\n");
	}
	return (0);
}
