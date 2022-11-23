/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:10:01 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/23 20:57:03 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	free_split(char **split, size_t row)
{
	size_t	i;

	i = 0;
	while (i < row)
	{
		free(split[i]);
		++i;
	}
	free(split);
}

static char	*malloc_cpy(char const *s, size_t size, char c, size_t i)
{
	size_t	arr_count;
	char	*arr;

	arr_count = 0;
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (arr == 0)
		return (0);
	while (s[i] != c)
	{
		arr[arr_count] = s[i];
		++i;
		++arr_count;
	}
	arr[arr_count] = '\0';
	return (arr);
}

static void	count_col(char const *s, char **split, char c, size_t i)
{
	size_t	count;
	size_t	row;
	size_t	check;

	count = 0;
	row = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			++count;
			check = 0;
		}
		else if (s[i] == c && check == 0)
		{
			split[row] = malloc_cpy(s, count, c, i - count);
			if (split[row++] == (char *)0)
				free_split(split, row);
			check = 1;
			count = 0;
		}
		++i;
	}
	if (check == 0)
		split[row] = malloc_cpy(s, count, c, i - count);
}

static size_t	count_row(char const *s, char c, size_t i)
{
	size_t	count;
	size_t	check;

	count = 0;
	check = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && check == 0)
		{
			++count;
			check = 1;
		}
		else if (s[i] == c)
			check = 0;
		++i;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] == c)
		++i;
	count = count_row(s, c, i);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (split == (char **)0)
		return ((char **)0);
	split[count] = (char *)0;
	if (count > 0)
		count_col(s, split, c, i);
	return (split);
}
