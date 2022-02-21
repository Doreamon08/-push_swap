/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:26:35 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/21 16:33:45 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	sab(int *a, int size_of_ar)
{
	int	temp;

	if (!a || size_of_ar <= 1)
		return (0);
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	return (0);
}

void	pab(int **a, int **b, t_size *size, char c)
{
	if (c == 'b' && size->sizeb == 0)
		return ;
	if (c == 'a' && size->sizea == 0)
		return ;
	*b = shiftdown(*b, size, c);
	*b[0] = *a[0];
	*a = delfirst(*a, size, c);
}

int	rab(int *a, int size)
{
	int	i;
	int	temp;

	i = 0;
	if (!size)
		return (0);
	temp = a[0];
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = temp;
	return (0);
}

int	rrab(int *ab, int size)
{
	int	i;
	int	temp;
	int	temp2;

	temp = ab[0];
	i = 1;
	if (!size)
		return (0);
	while (i < size)
	{
		if (i == size - 1)
			ab[0] = ab[i];
		temp2 = ab[i];
		ab[i] = temp;
		temp = temp2;
		i++;
	}
	return (0);
}
