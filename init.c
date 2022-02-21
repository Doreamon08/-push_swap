/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:18:51 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/20 00:17:51 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	digit(char *str)
{
	t_variables	variables;

	variables.flag = 1;
	variables.i = 0;
	while (str[variables.i])
	{
		if (str[variables.i] == '-' || (str[variables.i] == '+'))
		{
			if ((str[variables.i + 1] >= 48 && str[variables.i + 1] <= 57)
				&& !(str[variables.i - 1] >= 48 && str[variables.i - 1] <= 57))
				variables.i = variables.i + 2;
			else
				return (0);
		}
		else if (str[variables.i] >= 48 && str[variables.i] <= 57)
			variables.i++;
		else if (str[variables.i] == ' ')
		{
			variables.flag = 2;
			variables.i++;
		}
		else
			return (0);
	}
	return (variables.flag);
}

void	if_one_argument(t_size *size, char **ac, int *a, int *i)
{
	int		l;
	char	**one_argument;

	l = 0;
	one_argument = ft_split(ac[*a], ' ');
	while (one_argument[l])
	{
		size->a[*i] = chartonum(one_argument[l], size);
		free(one_argument[l]);
		l++;
		*i = *i + 1;
	}
	*a = *a + 1;
	free(one_argument);
}

int	how_much_ints(char **ac)
{
	int	count_of_ints;
	int	i;

	i = 0;
	count_of_ints = 0;
	while (ac[i])
	{
		count_of_ints = count_of_ints + find_word_count(ac[i++], ' ');
	}
	return (count_of_ints - 1);
}

int	initarrays_b(t_size *size)
{
	size->b = malloc(sizeof(int));
	size->sorted = sort(size->a, size->sizea);
	size->fic_a = create_fict(size);
	size->fic_b = malloc(sizeof(int));
	if (!size->b || !size->sorted || !size->fic_a || !size->fic_b)
		return (0);
	return (1);
}

int	initarrays(t_size *size, char **ac, int ag)
{
	t_variables	variables;

	variables.i = 0;
	variables.l = 1;
	while (variables.i < ag)
	{
		if (!digit(ac[variables.l]))
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (0);
		}
		else if (digit(ac[variables.l]) == 2)
			if_one_argument(size, ac, &variables.l, &variables.i);
		else
		{
			size->a[variables.i] = chartonum(ac[variables.l], size);
			variables.i++;
			variables.l++;
		}
	}
	return (initarrays_b(size));
}
