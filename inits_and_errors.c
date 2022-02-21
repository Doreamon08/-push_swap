/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:12:04 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/20 00:18:24 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	inits_and_errors(t_size *size, char **ac)
{
	int	count_ints;

	count_ints = 0;
	count_ints = how_much_ints(ac);
	size->sizea = count_ints;
	size->sizeb = 0;
	size->a = malloc(sizeof(int) * count_ints);
	if (!size->a || !initarrays(size, ac, count_ints)
		|| repit(size) || issorted(size))
		return (0);
	return (count_ints);
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
