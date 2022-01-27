/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_for_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:33:55 by rabbie            #+#    #+#             */
/*   Updated: 2022/01/26 17:28:56 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*shiftdown(int *a, t_size *size, char c)
{
	int	*ac;
	int	sizeofstack;

	sizeofstack = 0;
	if (c == 'b')
		sizeofstack = size->sizea;
	else
		sizeofstack = size->sizeb;
	ac = malloc(sizeof(int) * (sizeofstack + 1));
	if (!ac)
		return (a);
	while (sizeofstack)
	{
		ac[sizeofstack] = a[sizeofstack - 1];
		sizeofstack--;
	}
	if (c == 'b')
		size->sizea++;
	else
		size->sizeb++;
	free(a);
	return (ac);
}

int	*delfirst(int *ab, t_size *size, char c)
{
	int	*abc;
	int	sizeofstack;

	sizeofstack = 0;
	if (!ab)
		return (ab);
	if (c == 'a')
		sizeofstack = size->sizea;
	else
		sizeofstack = size->sizeb;
	abc = malloc(sizeof(int) * (sizeofstack - 1));
	sizeofstack = sizeofstack - 1;
	while (sizeofstack)
	{
		abc[sizeofstack - 1] = ab[sizeofstack];
		sizeofstack--;
	}
	if (c == 'a')
	{
		size->sizea--;
	}
	else
		size->sizeb--;
	free(ab);
	return (abc);
}
