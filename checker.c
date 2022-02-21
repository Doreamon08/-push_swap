/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:23:59 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/21 03:13:01 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ag, char **ac)
{
	t_size	*size;
	char	*op;

	size = init_for_checker(ag, ac);
	op = get_next_line(0);
	while (op)
	{
		if (!what_the_op(size, op))
		{
			free(op);
			op = get_next_line(-1);
			free_for_checker(size);
		}
		free(op);
		op = get_next_line(0);
	}
	if (issorted(size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_for_checker(size);
}
