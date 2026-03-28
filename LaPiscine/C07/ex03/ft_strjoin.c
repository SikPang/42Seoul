/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:48:41 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/18 10:48:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	set_number(char *arr, char *sep, char **strs, int size)
{
	int	i;
	int	j;
	int	arr_count;

	i = 0;
	arr_count = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			arr[arr_count++] = strs[i][j++];
		j = 0;
		if (i < size - 1)
		{
			while (sep[j] != '\0')
				arr[arr_count++] = sep[j++];
		}
		++i;
	}
	arr[arr_count] = 0;
}

int	get_length(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	length;

	length = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			++length;
			++j;
		}
		++i;
	}
	i = 0;
	while (sep[i] != '\0')
		++i;
	length += (i * size - 1);
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		length;

	if (size == 0)
	{
		arr = (char *)malloc(sizeof(char) * 1);
		arr[0] = 0;
		return (arr);
	}
	length = get_length(size, strs, sep);
	arr = (char *)malloc(sizeof(char) * (length + 1));
	if (arr == 0)
		return (0);
	set_number(arr, sep, strs, size);
	return (arr);
}
