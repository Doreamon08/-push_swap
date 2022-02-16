/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:43:54 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/15 22:44:54 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	chartonum(char *ch)
{
	int	num;
	int	i;
	int	sign;

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
	return (num / 10 * sign);
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
				write(1, "Error", 5);
				write(1, "\n", 1);
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

	size = malloc(sizeof(t_size));
	if (!size)
		return (0);
	size->sizea = ag - 1;
	size->sizeb = 0;
	if (ag == 1)
	{
		printf("Error\n");
		return (1);
	}
	if (!initarrays(size, ac, ag))
		return (1);
	if (repit(size))
		return (1);
	if (issorted(size))
	{
		freemem(size);
		return (0);
	}
	// printer(ag - 1, size, size->a, size->b);
	// printf("%d\n", ag);
	if (ag == 4)
	{
		sorting_for_three(size);
		return (0);
	}
	complite_sorting(size);
	return (0);
}
