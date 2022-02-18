/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:47:24 by rabbie            #+#    #+#             */
/*   Updated: 2022/02/17 23:29:36 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	find_word_count(char const *s, char c)
{
	int		word_count;
	int		i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word_count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word_count);
}

char	*split_word(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return ((void *)0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	free_words(char **result, int i)
{
	while (i > 0)
	{
		free(result[i - 1]);
		i--;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;
	int		i;

	if (!s)
		return ((void *)0);
	word_count = find_word_count(s, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return ((void *)0);
	i = 0;
	while (i < word_count)
	{
		while (*s && *s == c)
			s++;
		result[i] = split_word(s, c);
		if (!result[i])
			free_words(result, i);
		i++;
		while (*s && *s != c)
			s++;
	}
	result[i] = (void *)0;
	return (result);
}
