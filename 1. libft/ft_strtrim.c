/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:07:40 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/24 16:34:54 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	set_sep(int *sep, unsigned char *set)
{
	size_t	i;

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

	s1_len = ft_strlen(s1);
	start_index = 0;
	end_index = s1_len - 1;
	ft_bzero((void *)sep, 256);
	set_sep(sep, (unsigned char *)set);
	while (sep[(int)s1[start_index]] == 1)
		++start_index;
	if (start_index == s1_len)
		return (ft_calloc(1, sizeof(char)));
	while (sep[(int)s1[end_index]] == 1)
		--end_index;
	new_str = (char *)ft_calloc(end_index - start_index + 2, sizeof(char));
	if (new_str == (char *)0)
		return ((char *)0);
	ft_memcpy(new_str, s1+start_index, end_index - start_index + 1);
	return (new_str);
}

// #include <stdio.h>
// int main()
// {
// 	//char *str = "lorem \n ipsum \t dolor \n sit \t amet";
// 	char *str = "lllll";
// 	char *sep = " ";
// 	printf("%s", ft_strtrim(str, sep));
// }