/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:10:01 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/28 17:08:25 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	init_var(char const *s, char c, size_t *row, size_t *col)
{
	size_t	i;

	i = 0;
	while (s[i] == c)
		++i;
	*row = 0;
	*col = 0;
	return (i);
}

char	**free_all(char **new, size_t row)
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

void	copy_str(char **new, char c, size_t i, char const *s)
{
	size_t	row;
	size_t	col;

	i = init_var(s, c, &row, &col);
	while (s[i] != '\0')
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

char	**init_col(char **new, char c, size_t i, char const *s)
{
	size_t	row;
	size_t	col;

	i = init_var(s, c, &row, &col);
	while (s[i] != '\0')
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

	i = init_var(s, c, &row, &col);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			++row;
		++i;
	}
	if (i == 0 || s[i - 1] == c)
		new = (char **)ft_calloc(row + 1, sizeof(char *));
	else
		new = (char **)ft_calloc(row + 2, sizeof(char *));
	if (new == (char **)0)
		return ((char **)0);
	if (init_col(new, c, i, s) == (char **)0)
		return ((char **)0);
	copy_str(new, c, i, s);
	return (new);
}

// #include <stdio.h>
// int main()
// {
// 	int i, j;

// 	i = 0;
// 	j = 0;
// 	char **sp = ft_split("hello!", '');
// 	while (sp[i])
// 	{
// 		while (sp[i][j])
// 		{
// 			printf("%c", sp[i][j]);
// 			++j;
// 		}
// 		printf("\n");
// 		++i;
// 	}
// 	printf("\n");

// 	i = 0;
// 	j = 0;
// 	char **sp2 = ft_split("xxxxxxxxhello!", 'x');
// 	while (sp2[i])
// 	{
// 		while (sp2[i][j])
// 		{
// 			printf("%c", sp2[i][j]);
// 			++j;
// 		}
// 		printf("\n");
// 		++i;
// 	}
// 	printf("\n");

// 	i = 0;
// 	j = 0;
// 	char **sp3 = ft_split("hello!zzzzzzzz", 'z');
// 	while (sp3[i])
// 	{
// 		while (sp3[i][j])
// 		{
// 			printf("%c", sp3[i][j]);
// 			++j;
// 		}
// 		printf("\n");
// 		++i;
// 	}
// }