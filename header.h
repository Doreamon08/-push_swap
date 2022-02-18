/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:00:12 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/18 21:06:47 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_size
{
	int	*a;
	int	*b;
	int	*fic_a;
	int	*fic_b;
	int	*sorted;
	int	sizea;
	int	sizeb;
	int	count_ints;
}				t_size;

typedef struct s_variables
{
	int		max_num;
	int		siz;
	int		max_bits;
	int		i;
	int		l;
	int		sign;
	long	num;
	int		flag;
}				t_variables;

int		printer(int sizeAg, t_size *size, int *a, int *b);

int		sab(int *a);
void	pab(int **a, int **b, t_size *size, char c);
int		rab(int *a, int size);
int		rrab(int *ab, int size);
void	ra(t_size *size);
void	sa(t_size *size);
void	operation(t_size *size, int numOp);
int		find_word_count(char const *s, char c);
char	**ft_split(char const *s, char c);
int		how_much_ints(char **ac);
void	if_one_agument(t_size *size, char **ac, int *a, int *i);
int		*shiftdown(int *a, t_size *size, char c);
int		*delfirst(int *ab, t_size *size, char c);

int		*copyar(int	*ar, int size);
int		whattheindex(t_size *size, int i);
int		*create_fict(t_size *size);
int		chartonum(char *ch);
int		*sort(int *a, int size);
int		issorted(t_size *size);
int		repit(t_size *size);
int		inits_and_errors(t_size *size, char **ac, int ag);
int		initarrays(t_size *size, char **ac, int ag);
void	complite_sorting(t_size *size);
void	sorting_for_three(t_size *size);
void	sorting_for_five(t_size *size);
void	freemem(t_size *size);

#endif