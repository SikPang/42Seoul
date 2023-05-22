/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:49:40 by sokwon            #+#    #+#             */
/*   Updated: 2023/05/01 14:27:04 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>	// size_t
#include <stdlib.h>	// NULL, malloc()

static _Bool	ft_is_sep(const char c, const char sep)
{
	return (c == '\0' || c == sep || c == '\n');
}

static size_t	ft_count_num_of_words(const char *s, const char c)
{
	_Bool	flag_in_word;
	size_t	count;

	flag_in_word = 0;
	count = 0;
	while (*s != '\0')
	{
		if (!ft_is_sep(*s, c) && !flag_in_word)
		{
			count++;
			flag_in_word = 1;
		}
		else if (ft_is_sep(*s, c) && flag_in_word)
			flag_in_word = 0;
		s++;
	}
	return (count);
}

static _Bool	ft_insert_words(char **words, const char *s, const char c)
{
	_Bool		flag_in_word;
	const char	*head;

	flag_in_word = 0;
	while (1)
	{
		if (!ft_is_sep(*s, c) && !flag_in_word)
		{
			head = s;
			flag_in_word = 1;
		}
		else if (ft_is_sep(*s, c) && flag_in_word)
		{
			*words = ft_substr(head, 0, (s - head));
			if (*words == NULL)
				return (0);
			flag_in_word = 0;
			words++;
		}
		if (*s == '\0')
			return (1);
		s++;
	}
}

static void	ft_clear_words(char **words)
{
	char	**now;

	now = words;
	while (*now != NULL)
	{
		free(*now);
		now++;
	}
	free(words);
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	size_t	num_of_words;

	num_of_words = ft_count_num_of_words(s, c);
	words = (char **)ft_calloc((num_of_words + 1), sizeof(char *));
	if (words == NULL)
		return (NULL);
	if (num_of_words > 0 && ft_insert_words(words, s, c) == 0)
	{
		ft_clear_words(words);
		return (NULL);
	}
	return (words);
}
