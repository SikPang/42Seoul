/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:01:54 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/09 14:53:40 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_split_bonus.h"

static int	free_all(char **strs, size_t row)
{
	size_t	i;

	i = 0;
	while (i < row)
	{
		free(strs[i]);
		strs[i] = (char *)0;
		++i;
	}
	free(strs);
	strs = 0;
	return (0);
}

static void	copy_str(char **result, char *s, char c)
{
	int	row;
	int	col;
	int	i;
	int	is_quote;

	row = 0;
	col = 0;
	i = 0;
	is_quote = 0;
	while (s[i] != '\0')
	{
		check_quote(s[i], &is_quote);
		if (i != 0 && s[i] == c && s[i - 1] != c && !is_quote)
		{
			col = 0;
			++row;
		}
		else if ((s[i] != '\'' && s[i] != '\"' && s[i] != c)
			|| (s[i] == c && is_quote))
		{
			result[row][col] = s[i];
			++col;
		}
		++i;
	}
}

static int	init_col(char **result, char *s, char c)
{
	int		cnt;
	int		row;
	int		i;
	int		is_quote;

	cnt = 0;
	row = 0;
	i = -1;
	is_quote = 0;
	while (s[++i] != '\0')
	{
		check_quote(s[i], &is_quote);
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0') && !is_quote)
		{
			result[row] = (char *)malloc(++cnt + 1);
			if (result[row] == NULL)
				return (free_all(result, row));
			result[row++][cnt] = '\0';
			cnt = 0;
		}
		else if ((s[i] != '\'' && s[i] != '\"' && s[i] != c)
			|| (s[i] == c && is_quote))
			++cnt;
	}
	return (1);
}

static char	**init_row(char *s, char c)
{
	char	**result;
	int		cnt;
	int		i;
	int		is_quote;

	cnt = 0;
	i = 0;
	is_quote = 0;
	while (s[i] != '\0')
	{
		check_quote(s[i], &is_quote);
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0') && !is_quote)
			++cnt;
		++i;
	}
	result = (char **)malloc((cnt + 1) * sizeof(char *));
	if (is_quote || result == NULL)
		return (NULL);
	result[cnt] = NULL;
	return (result);
}

char	**ft_split(char *s, char c)
{
	char	**result;

	if (s == NULL)
		return (NULL);
	if (s[0] == '\0')
	{
		result = malloc(sizeof(char *));
		if (result == 0)
			return (result);
		result[0] = NULL;
		return (result);
	}
	while (*s == c)
		++s;
	result = init_row(s, c);
	if (result == NULL)
		return (NULL);
	if (init_col(result, s, c) == 0)
		return (NULL);
	copy_str(result, s, c);
	return (result);
}
