/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_for_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:45:24 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/17 16:10:15 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sorting_for_five(t_size *size)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (size->fic_a[0] != 0 || size->fic_a[0] != 1)
			ra(size);
		else
		{
			operation(size, 0);
			i++;
		}
	}
	sorting_for_three(size);
	operation(size, 2);
	operation(size, 2);
	if (!sort(size->fic_a, size->sizea))
		sa(size);
}
