/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:43:54 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/19 17:27:03 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ag, char **ac)
{
	t_size	*size;
	int		count_ints;

	size = malloc(sizeof(t_size));
	if (!size || ag == 0)
		return (0);
	count_ints = inits_and_errors(size, ac, ag);
	if (!count_ints)
	{
		freemem(size);
		return (0);
	}
	if (count_ints == 2)
		write(1, "sa\n", 3);
	else if (count_ints == 3)
		sorting_for_three(size);
	else if (count_ints == 5)
		sorting_for_five(size);
	else
		complite_sorting(size);
	freemem(size);
	return (0);
}
