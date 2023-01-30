/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:10:01 by kwsong            #+#    #+#             */
/*   Updated: 2023/01/30 18:46:10 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utility.h"

static size_t	init_var(char const *s, char c, size_t *row, size_t *col)
{
	size_t	i;

	i = 0;
	while (s[i] == c)
		++i;
	*row = 0;
	*col = 0;
	return (i);
}

static char	**free_all(char **new, size_t row)
{
	size_t	i;

	i = 0;
	while (i < row)
	{
		free(new[i]);
		new[i] = (char *)0;
		++i;
	}
	free(new);
	new = (char **)0;
	return ((char **)0);
}

static void	copy_str(char **new, char c, size_t i, char const *s)
{
	size_t	row;
	size_t	col;

	i = init_var(s, c, &row, &col);
	while (s[i] != '\0' && s[i] != '\n')
	{
		if (s[i] == c && s[i - 1] != c)
		{
			col = 0;
			++row;
		}
		else if (s[i] != c)
		{
			new[row][col] = s[i];
			++col;
		}
		++i;
	}
}

static char	**init_col(char **new, char c, size_t i, char const *s)
{
	size_t	row;
	size_t	col;

	i = init_var(s, c, &row, &col);
	while (s[i] != '\0' && s[i] != '\n')
	{
		if (s[i] == c && s[i - 1] != c)
		{
			new[row] = (char *)ft_calloc(col + 1, sizeof(char));
			if (new[row] == (char *)0)
				return (free_all(new, row));
			col = 0;
			++row;
		}
		else if (s[i] != c)
			++col;
		++i;
	}
	if (col != 0)
	{
		new[row] = (char *)ft_calloc(col + 1, sizeof(char));
		if (new[row] == (char *)0)
			return (free_all(new, row));
	}
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	row;
	size_t	col;
	size_t	i;

	if (s == 0)
		return (0);
	if (s[0] == '\0')
		return ((char **)ft_calloc(1, sizeof(char *)));
	i = init_var(s, c, &row, &col);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			++row;
		++i;
	}
	if (i != 0 && s[i - 1] != c)
		++row;
	new = (char **)ft_calloc(row + 1, sizeof(char *));
	if (new == 0)
		return ((char **)0);
	if (init_col(new, c, i, s) == (char **)0)
		return ((char **)0);
	copy_str(new, c, i, s);
	return (new);
}
