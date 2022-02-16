/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:00:12 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/15 22:06:07 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

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
}				t_size;

typedef struct s_variables
{
	int	max_num;
	int	siz;
	int	max_bits;
	int	i;
	int	l;
	int	score;
}				t_variables;

int		printer(int sizeAg, t_size *size, int *a, int *b);

int		sab(int *a);
void	pab(int **a, int **b, t_size *size, char c);
int		rab(int *a, int size);
int		rrab(int *ab, int size);
void	operation(t_size *size, int numOp);
int		*shiftdown(int *a, t_size *size, char c);
int		*delfirst(int *ab, t_size *size, char c);

int		*copyar(int	*ar, int size);
int		whattheindex(t_size *size, int i);
int		*create_fict(t_size *size);
int		chartonum(char *ch);
int		*sort(int *a, int size);
int		initarrays(t_size *size, char **ac, int ag);
void	complite_sorting(t_size *size);
void	sorting_for_three(t_size *size);
void	freemem(t_size *size);

#endif