/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_for_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:20:18 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/16 14:43:06 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	variants(t_size *size, int var)
{
	if ()
}

void sorting_for_three(t_size *size)
{
	if (size->fic_a[1] > size->fic_a[2] && size->fic_a[2] > size->fic_a[0])
	{
		sab(size->fic_a);
		sab(size->a);
		rab(size->fic_a, size->sizea);
		rab(size->a, size->sizea);
		printf("sa\n");
		printf("ra\n");
	}
	else if (size->fic_a[2] > size->fic_a[0] && size->fic_a[0] > size->fic_a[1])
	{
		sab(size->fic_a);
		sab(size->a);
		printf("sa\n");
	}
	else if (size->fic_a[1] > size->fic_a[0] && size->fic_a[0] > size->fic_a[2])
	{
		rrab(size->fic_a, size->sizea);
		rrab(size->a, size->sizea);
		printf("rra\n");
	}
	else if (size->fic_a[0] > size->fic_a[2] && size->fic_a[2] > size->fic_a[1])
	{
		rab(size->fic_a, size->sizea);
		rab(size->a, size->sizea);
		printf("ra\n");
	}
	else if (size->fic_a[0] > size->fic_a[1] && size->fic_a[1] > size->fic_a[2])
	{
		sab(size->fic_a);
		sab(size->a);
		rrab(size->fic_a, size->sizea);
		rrab(size->a, size->sizea);
		printf("sa\n");
		printf("rra\n");
	}
}
