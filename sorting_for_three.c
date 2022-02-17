/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_for_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:20:18 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/17 17:05:13 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_size *size)
{
	sab(size->fic_a);
	sab(size->a);
	write(1, "sa\n", 3);
}

void	ra(t_size *size)
{
	rab(size->fic_a, size->sizea);
	rab(size->a, size->sizea);
	write(1, "ra\n", 3);
}

void	rra(t_size *size)
{
	rrab(size->fic_a, size->sizea);
	rrab(size->a, size->sizea);
	write(1, "rra\n", 4);
}

void	sorting_for_three(t_size *size)
{
	if (size->fic_a[1] > size->fic_a[2] && size->fic_a[2] > size->fic_a[0])
	{
		sa(size);
		ra(size);
	}
	else if (size->fic_a[2] > size->fic_a[0] && size->fic_a[0] > size->fic_a[1])
		sa(size);
	else if (size->fic_a[1] > size->fic_a[0] && size->fic_a[0] > size->fic_a[2])
		rra(size);
	else if (size->fic_a[0] > size->fic_a[2] && size->fic_a[2] > size->fic_a[1])
		ra(size);
	else if (size->fic_a[0] > size->fic_a[1] && size->fic_a[1] > size->fic_a[2])
	{
		sa(size);
		rra(size);
	}
}

void	sorting_for_five(t_size *size)
{
	int	i;

	i = 0;
	// printer(6, size, size->a, size->b);
	while (i < 2)
	{
		if (size->fic_a[0] == 0 || size->fic_a[0] == 1)
		{
			operation(size, 0);
			i++;
			// printer(6, size, size->a, size->b);
		}
		else
		{
			ra(size);
			// printer(6, size, size->a, size->b);
		}
	}
	// printer(6, size, size->a, size->b);
	sorting_for_three(size);
	// printer(6, size, size->a, size->b);
	operation(size, 2);
	// printer(6, size, size->a, size->b);
	operation(size, 2);
	// printer(6, size, size->a, size->b);
	if (!issorted(size))
		sa(size);
	// printer(6, size, size->a, size->b);
}
