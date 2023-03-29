/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:58:15 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/20 11:28:37 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

void	init_space(int *is_space)
{
	int	i;

	i = 0;
	while (i < 128)
	{
		is_space[i] = 0;
		++i;
	}
	i = 9;
	while (i < 14)
	{
		is_space[i] = 1;
		++i;
	}
	is_space[32] = 1;
}

char	*pm_dup(char *str, int size, int i)
{
	int		count;
	char	*arr;

	count = 0;
	arr = (char *)malloc(sizeof(char) * size + 1);
	if (arr == 0)
		return (0);
	while (count < size)
	{
		arr[count] = str[i];
		++i;
		++count;
	}
	arr[count] = '\0';
	return (arr);
}

void	count_col(char *str, int *is_space, char *arr[], int i)
{
	int	count;
	int	row;
	int	check;

	count = 0;
	row = 0;
	while (str[++i] != '\0' && is_space[(int)str[i]] == 1)
		;
	while (str[i] != '\0')
	{
		if (is_space[(int)str[i]] == 0)
		{
			++count;
			check = 0;
		}
		else if (is_space[(int)str[i]] == 1 && check == 0)
		{
			arr[row++] = pm_dup(str, count, i - count);
			check = 1;
			count = 0;
		}
		++i;
	}
	if (check == 0)
		arr[row] = pm_dup(str, count, i - count);
}

int	count_row(char *str, int *is_space)
{
	int	i;
	int	count;
	int	check;

	i = -1;
	count = 0;
	check = 0;
	while (str[++i] != '\0' && is_space[(int)str[i]] == 1)
		;
	while (str[i] != '\0')
	{
		if (is_space[(int)str[i]] == 0 && check == 0)
		{
			++count;
			check = 1;
		}
		else if (is_space[(int)str[i]] == 1)
			check = 0;
		++i;
	}
	return (count);
}

char	**split(char *str, int *length)
{
	char	**arr;
	int		is_space[128];
	int		count;

	if (str == 0)
		return (0);
	init_space(is_space);
	count = count_row(str, is_space);
	*length = count;
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (arr == 0)
		return (0);
	arr[count] = 0;
	if (count > 0)
		count_col(str, is_space, arr, -1);
	return (arr);
}

/*
#include <stdio.h>
void print(char *s1)
{
	char **words = split(s1);
	printf("address : %p\n", words);
	if (!*words)
	{
		printf("(blank)\n");
	}
	while (*words)
		printf("%s\n", *(words++));
	printf("\n");
}

int	main(void)
{
	char ch[20] = {'a', 9, 'b', 10, 'c', 11, 'd', 12, 'e', 13, 'f', 32, 'g'};
	print(" hello i am song");
	print(ch);
}
*/
