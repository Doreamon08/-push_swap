/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:23:59 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/19 19:51:26 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	main(int ag, char **ac)
{
	t_size	*size;
	int		count_ints;
	char	*op;

	size = malloc(sizeof(t_size));
	if (!size || ag == 0)
		return (0);
	count_ints = inits_and_errors(size, ac, ag);
	if (!count_ints)
	{
		freemem(size);
		return (0);
	}
	while (op = get_next_line(0))
	{
		// while (i < ag - 1)
		// {
		// 	printf("%d | %d \n", a[i], b[i]);
		// 	i++;
		// }
		// printer(ag - 1, size, size->a, size->b);
		// printf("\n");
		// printf("\n%d - sizea, %d - sizeb\n", size->sizea, size->sizeb);
		// printf("%d - score\n", i);
		// complite_sorting(size, ag - 1);
		// printf("\n");
		// printer(count_ints, size, size->a, size->b);
		// printf("%s\n", op);
		if (op[0] == 's' && op[1] == 'a' && op[2] == '\n')//sa
			sab(size->a);
		else if (op[0] == 's' && op[1] == 'b' && op[2] == '\n')//sb
			sab(size->b);
		else if (op[0] == 's' && op[1] == 's' && op[2] == '\n')//ss
		{
			sab(size->a);
			sab(size->b);
		}
		else if (op[0] == 'p' && op[1] == 'a' && op[2] == '\n')//pa
			pab(&size->b, &size->a, size, 'b');
		else if (op[0] == 'p' && op[1] == 'b' && op[2] == '\n')//pb
			pab(&size->a, &size->b, size, 'a');
		else if (op[0] == 'r' && op[1] == 'a' && op[2] == '\n')//ra
			rab(size->a, size->sizea);
		else if (op[0] == 'r' && op[1] == 'b' && op[2] == '\n')//rb
			rab(size->b, size->sizeb);
		else if (op[0] == 'r' && op[1] == 'r' && op[2] == '\n')//rr
		{
			rab(size->a, size->sizea);
			rab(size->b, size->sizeb);
		}
		else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'a' && op[3] == '\n')//rra
			rrab(size->a, size->sizea);
		else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'b' && op[3] == '\n')//rrb
			rrab(size->a, size->sizeb);
		else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'r' && op[3] == '\n')//rrr
		{
			rrab(size->a, size->sizea);
			rrab(size->b, size->sizeb);
		}
		else
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (0);
		}
		// printf("\n");
		// i++;
	}
	if (issorted(size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
