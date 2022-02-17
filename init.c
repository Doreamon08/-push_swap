/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:18:51 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/16 16:36:04 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

int	initarrays(t_size *size, char **ac, int ag)
{
	int	i;

	i = 1;
	size->a = malloc(sizeof(int) * (ag - 1));
	if (!size->a)
		return (0);
	while (i < ag)
	{
		if (!digit(ac[i]))
		{
			write(STDERR_FILENO, "Error\n", 6);
			free(size->a);
			free(size);
			return (0);
		}
		size->a[i - 1] = chartonum(ac[i]);
		i++;
	}
	size->b = malloc(sizeof(int));
	size->sorted = sort(size->a, size->sizea);
	size->fic_a = create_fict(size);
	size->fic_b = malloc(sizeof(int));
	if (!size->b || !size->sorted || !size->fic_a || !size->fic_b)
		return (0);
	return (1);
}
