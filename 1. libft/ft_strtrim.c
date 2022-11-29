/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:07:40 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/29 20:45:00 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_sep(int *sep, unsigned char *set)
{
	size_t	i;

	i = 0;
	while (i < 256)
	{
		sep[i] = 0;
		++i;
	}
	i = 0;
	while (set[i] != '\0')
	{
		sep[(int)set[i]] = 1;
		++i;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		sep[256];
	char	*new_str;
	size_t	s1_len;
	size_t	start_index;
	size_t	end_index;

	if (!s1)
		return ((char *)0);
	if (!set)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	start_index = 0;
	end_index = s1_len - 1;
	set_sep(sep, (unsigned char *)set);
	while (sep[(int)s1[start_index]] == 1)
		++start_index;
	if (start_index == s1_len)
		return (ft_calloc(1, sizeof(char)));
	while (sep[(int)s1[end_index]] == 1)
		--end_index;
	new_str = ft_substr(s1, start_index, end_index - start_index + 1);
	if (new_str == (char *)0)
		return ((char *)0);
	return (new_str);
}

// #include <stdio.h>
// int main()
// {
// 	//char *str = "lorem \n ipsum \t dolor \n sit \t amet";
// 	//char *str = "\0lllll";
// 	char *sep = 0;
// 	char str[10] = {'\0', 'l', 'l'};
// 	//char sep[1] = {'\0'};
// 	printf("%s", ft_strtrim(str, sep));
// }