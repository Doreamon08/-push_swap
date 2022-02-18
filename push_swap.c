/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:43:54 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/18 01:08:28 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	chartonum(char *ch)
{
	long	num;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	num = 0;
	while (ch[i])
	{
		if (ch[i] == '-')
		{
			sign *= -1;
			i++;
		}
		num += (ch[i] - 48) % 10;
		num *= 10;
		i++;
	}
	num = num / 10 * sign;
	if (num < INT_MIN || num > INT_MAX)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(0);
	}
	return ((int)num);
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
				freemem(size);
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

int	main(int ag, char **ac)
{
	t_size	*size;
	int		count_ints;

	size = malloc(sizeof(t_size));
	if (!size)
		return (0);
	if (ag == 1)
		return (1);
	count_ints = how_much_ints(ac);
	size->sizea = count_ints;
	size->sizeb = 0;
	// printf("%d - counts of ints\n", count_ints);
	if (!initarrays(size, ac, count_ints))
		return (1);
	if (repit(size))
		return (1);
	if (issorted(size))
	{
		freemem(size);
		return (0);
	}
	if (count_ints == 2)
	{
		write(1, "sa\n", 3);
		return (0);
	}
	// printer(ag - 1, size, size->a, size->b);
	// printf("%d\n", ag);
	if (count_ints == 3)
	{
		sorting_for_three(size);
		freemem(size);
		return (0);
	}
	if (count_ints == 5)
	{
		sorting_for_five(size);
		freemem(size);
		return (0);
	}
	complite_sorting(size);
	freemem(size);
	return (0);
}
