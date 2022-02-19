/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:26:29 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/19 23:25:00 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	mini_freemem(t_size *size)
{
	write(STDERR_FILENO, "Error\n", 6);
	free(size->a);
	free(size);
	exit (0);
}

int	chartonum(char *ch, t_size *size)
{
	t_variables	variables;

	variables.sign = 1;
	variables.i = 0;
	variables.num = 0;
	if (ch[variables.i] == '-')
	{
		variables.sign *= -1;
		variables.i++;
	}
	else if (ch[variables.i] == '+')
		variables.i++;
	while (variables.i < (int)ft_strlen(ch))
	{
		variables.num += (ch[variables.i] - 48) % 10;
		if (variables.i != (int)ft_strlen(ch) - 1)
			variables.num *= 10;
		variables.i++;
	}
	variables.num = variables.num * variables.sign;
	if (variables.num < INT_MIN || variables.num > INT_MAX)
		mini_freemem(size);
	return ((int)variables.num);
}

int	*sort(int *a, int size)
{
	int	i;
	int	l;
	int	temp;
	int	*sorted;

	sorted = copyar(a, size);
	i = 1;
	l = 0;
	temp = 0;
	while (l < size)
	{
		while (i < size)
		{
			if (sorted[i] < sorted[l])
			{
				temp = sorted[l];
				sorted[l] = sorted[i];
				sorted[i] = temp;
			}
			i++;
		}
		l++;
		i = l + 1;
	}
	return (sorted);
}

int	repit(t_size *size)
{
	int	i;
	int	l;

	l = 1;
	i = 0;
	while (i < size->sizea)
	{
		while (l < size->sizea)
		{
			if (size->a[i] == size->a[l])
			{
				write(STDERR_FILENO, "Error\n", 6);
				return (1);
			}
			l++;
		}
		i++;
		l = i + 1;
	}
	return (0);
}

int	issorted(t_size *size)
{
	int	i;

	i = 0;
	while (i < size->sizea)
	{
		if (size->a[i] != size->sorted[i])
			return (0);
		i++;
	}
	return (1);
}
