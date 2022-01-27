/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:09:40 by rabbie            #+#    #+#             */
/*   Updated: 2022/01/27 00:06:47 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*copyar(int	*ar, int size)
{
	int	*copyar;
	int	i;

	copyar = malloc(sizeof(int) * size);
	if (!copyar)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copyar[i] = ar[i];
		i++;
	}
	return (copyar);
}

int	whattheindex(t_size *size, int i)
{
	int	index;

	index = 0;
	while (index < size->sizea)
	{
		if (size->sorted[index] == i)
		{
			return (index);
		}
		index++;
	}
	return (-1);
}

int	*create_fict(t_size *size)
{
	int	*fict_a;
	int	i;
	int	l;

	fict_a = malloc(sizeof(int) * size->sizea);
	if (!fict_a)
		return (NULL);
	i = 0;
	while (i < size->sizea)
	{
		fict_a[i] = whattheindex(size, size->a[i]);
		i++;
	}
	return (fict_a);
}

void	freemem(t_size *size)
{
	free(size->a);
	free(size->b);
	free(size->fic_a);
	free(size->fic_b);
	free(size->sorted);
	free(size);
}

void	operation(t_size *size, int numOp)
{
	if (numOp == 0)
	{
		pab(&size->a, &size->b, size, 'a');
		size->sizea++;
		size->sizeb--;
		pab(&size->fic_a, &size->fic_b, size, 'a');
		printf ("pb\n");
	}
	if (numOp == 1)
	{
		rab(size->a, size->sizea);
		rab(size->fic_a, size->sizea);
		printf ("ra\n");
	}
	if (numOp == 2)
	{
		pab(&size->b, &size->a, size, 'b');
		size->sizeb++;
		size->sizea--;
		pab(&size->fic_b, &size->fic_a, size, 'b');
		printf ("pa\n");
	}
}

void	complite_sorting(t_size *size, int ag)
{
	t_variables	variables;

	variables.i = 0;
	variables.l = 0;
	variables.max_bits = 0;
	variables.siz = size->sizea;
	variables.max_num = size->sizea;
	while ((variables.max_num >> variables.max_bits) != 0)
		variables.max_bits++;
	while (variables.i < variables.max_bits)
	{
		while (variables.l < variables.siz)
		{
			if ((size->fic_a[0] >> variables.i) & 1 == 1)
			{
				operation(size, 1);
				printer(ag, size, size->a, size->b);
				printf("\n");
			}
			else
			{
				operation(size, 0);
				printer(ag, size, size->a, size->b);
				printf("\n");
			}
			variables.l++;
		}
		while (size->sizeb != 0)
		{
			operation(size, 2);
			printer(ag, size, size->a, size->b);
			printf("\n");
		}
		variables.i++;
		variables.l = 0;
	}
	printer(ag, size, size->a, size->b);
	freemem(size);
}
