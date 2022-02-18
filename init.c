/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:18:51 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/18 01:35:45 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**if_one_agument(char **ac, char *str);

int	digit(char **ac, char *str)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '-' || (str[i] == '+'))
		{
			i++;
			if ((str[i] >= 48 && str[i] <= 57)
				&& !(str[i - 2] >= 48 && str[i - 2] <= 57))
				i++;
			else
				return (0);
		}
		else if (str[i] >= 48 && str[i] <= 57)
			i++;
		else if (str[i] == ' ')
		{
			flag = 2;
			i++;
		}
		else
			return (0);
	}
	return (flag);
}

char	**if_one_agument(char **ac, char *str)
{
	// char	**new_ac;
	str = "23\0";
	while (*ac)
		printf ("%s\n", *ac++);
	exit (0);
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

int	initarrays(t_size *size, char **ac, int ag)
{
	int		i;
	int		l;
	int		a;
	char	**one_argument;

	i = 0;
	l = 0;
	a = 1;
	size->a = malloc(sizeof(int) * ag);
	if (!size->a)
		return (0);
	while (i < ag)
	{
		// printf("%s - ac[%d]\n", ac[a], a);
		if (!digit(ac, ac[a]))
		{
			write(STDERR_FILENO, "Error\n", 6);
			free(size->a);
			free(size);
			return (0);
		}
		else if (digit(ac, ac[a]) == 2)
		{
			one_argument = ft_split(ac[a], ' ');
			while (one_argument[l])
			{
				size->a[i] = chartonum(one_argument[l]);
				// printf("%d - size->a[%d]\n", size->a[i], i);
				free(one_argument[l]);
				l++;
				i++;
			}
			a++;
			l = 0;
			free(one_argument);
		}
		else
		{
			size->a[i] = chartonum(ac[a]);
			// printf("%d - size->a[%d]\n", size->a[i], i);
			i++;
			a++;
		}
	}
	size->b = malloc(sizeof(int));
	size->sorted = sort(size->a, size->sizea);
	size->fic_a = create_fict(size);
	size->fic_b = malloc(sizeof(int));
	if (!size->b || !size->sorted || !size->fic_a || !size->fic_b)
		return (0);
	return (1);
}
