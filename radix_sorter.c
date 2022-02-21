/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:09:40 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/21 16:15:11 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

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

void	operation(t_size *size, int numOp)
{
	if (numOp == 0)
	{
		pab(&size->a, &size->b, size, 'a');
		size->sizea++;
		size->sizeb--;
		pab(&size->fic_a, &size->fic_b, size, 'a');
		write(1, "pb\n", 3);
	}
	if (numOp == 1)
	{
		rab(size->a, size->sizea);
		rab(size->fic_a, size->sizea);
		write(1, "ra\n", 3);
	}
	if (numOp == 2)
	{
		pab(&size->b, &size->a, size, 'b');
		size->sizeb++;
		size->sizea--;
		pab(&size->fic_b, &size->fic_a, size, 'b');
		write(1, "pa\n", 3);
	}
}

void	complite_sorting(t_size *size)
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
			if (((size->fic_a[0] >> variables.i) & 1) == 1)
				operation(size, 1);
			else
				operation(size, 0);
			variables.l++;
		}
		while (size->sizeb != 0)
			operation(size, 2);
		variables.i++;
		variables.l = 0;
	}
}
