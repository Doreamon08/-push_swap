/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 03:11:47 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/21 16:32:03 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	inits_and_errors_for_checker(t_size *size, char **ac)
{
	int	count_ints;

	count_ints = 0;
	count_ints = how_much_ints(ac);
	size->sizea = count_ints;
	size->sizeb = 0;
	size->a = malloc(sizeof(int) * count_ints);
	if (!size->a || !initarrays(size, ac, count_ints) || repit(size))
		return (0);
	return (count_ints);
}

int	what_the_op_two(t_size *size, char *op)
{
	if (op[0] == 'r' && op[1] == 'r' && op[2] == '\n')
	{
		rab(size->a, size->sizea);
		rab(size->b, size->sizeb);
	}
	else if (op[0] == 'r' && op[1] == 'r'
		&& op[2] == 'a' && op[3] == '\n')
		rrab(size->a, size->sizea);
	else if (op[0] == 'r' && op[1] == 'r'
		&& op[2] == 'b' && op[3] == '\n')
		rrab(size->a, size->sizeb);
	else if (op[0] == 'r' && op[1] == 'r' 
		&& op[2] == 'r' && op[3] == '\n')
	{
		rrab(size->a, size->sizea);
		rrab(size->b, size->sizeb);
	}
	else
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	what_the_op(t_size *size, char *op)
{
	if (op[0] == 's' && op[1] == 'a' && op[2] == '\n')
		sab(size->a, size->sizea);
	else if (op[0] == 's' && op[1] == 'b' && op[2] == '\n')
		sab(size->b, size->sizeb);
	else if (op[0] == 's' && op[1] == 's' && op[2] == '\n')
	{
		sab(size->a, size->sizea);
		sab(size->b, size->sizeb);
	}
	else if (op[0] == 'p' && op[1] == 'a' && op[2] == '\n')
		pab(&size->b, &size->a, size, 'b');
	else if (op[0] == 'p' && op[1] == 'b' && op[2] == '\n')
		pab(&size->a, &size->b, size, 'a');
	else if (op[0] == 'r' && op[1] == 'a' && op[2] == '\n')
		rab(size->a, size->sizea);
	else if (op[0] == 'r' && op[1] == 'b' && op[2] == '\n')
		rab(size->b, size->sizeb);
	else
		return (what_the_op_two(size, op));
	return (1);
}

int	free_for_checker(t_size *size)
{
	free(size->a);
	free(size->b);
	free(size->fic_a);
	free(size->fic_b);
	free(size->sorted);
	free(size);
	exit (0);
}

t_size	*init_for_checker(int ag, char **ac)
{
	t_size	*size;
	int		count_ints;

	size = malloc(sizeof(t_size));
	if (!size || ag == 0)
		exit (0);
	count_ints = inits_and_errors_for_checker(size, ac);
	if (!count_ints)
	{
		freemem(size);
		exit (0);
	}
	return (size);
}
