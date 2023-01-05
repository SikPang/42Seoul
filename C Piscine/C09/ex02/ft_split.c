/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:10:01 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/18 11:16:12 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	set_sep(char *charset, int *is_sep)
{
	int				i;
	unsigned char	*un_charset;

	i = 0;
	un_charset = (unsigned char *)charset;
	while (i < 256)
	{
		is_sep[i] = 0;
		++i;
	}
	i = 0;
	while (charset[i] != '\0')
	{
		is_sep[(int)un_charset[i]] = 1;
		++i;
	}
	is_sep[0] = 1;
}

char	*my_strdup(char *str, int size, int i, int *is_sep)
{
	int		arr_count;
	char	*arr;

	arr_count = 0;
	arr = (char *)malloc(sizeof(char) * size + 1);
	if (arr == 0)
		return (0);
	while (is_sep[(int)str[i]] == 0)
	{
		arr[arr_count] = str[i];
		++i;
		++arr_count;
	}
	arr[arr_count] = '\0';
	return (arr);
}

void	count_col(char *str, int *is_sep, char *split[], int i)
{
	int	count;
	int	row;
	int	check;

	count = 0;
	row = 0;
	while (str[++i] != '\0' && is_sep[(int)str[i]] == 1)
		;
	while (str[i] != '\0')
	{
		if (is_sep[(int)str[i]] == 0)
		{
			++count;
			check = 0;
		}
		else if (is_sep[(int)str[i]] == 1 && check == 0)
		{
			split[row++] = my_strdup(str, count, i - count, is_sep);
			check = 1;
			count = 0;
		}
		++i;
	}
	if (check == 0)
		split[row] = my_strdup(str, count, i - count, is_sep);
}

int	count_row(char *str, int *is_sep)
{
	int	i;
	int	count;
	int	check;

	i = -1;
	count = 0;
	check = 0;
	while (str[++i] != '\0' && is_sep[(int)str[i]] == 1)
		;
	while (str[i] != '\0')
	{
		if (is_sep[(int)str[i]] == 0 && check == 0)
		{
			++count;
			check = 1;
		}
		else if (is_sep[(int)str[i]] == 1)
			check = 0;
		++i;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		is_sep[256];
	int		count;

	set_sep(charset, is_sep);
	count = count_row(str, is_sep);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (split == 0)
		return (0);
	split[count] = 0;
	if (count > 0)
		count_col(str, is_sep, split, -1);
	return (split);
}
