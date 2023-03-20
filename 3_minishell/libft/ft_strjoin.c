/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:34:57 by sokwon            #+#    #+#             */
/*   Updated: 2023/02/28 11:32:46 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// ft_strlen(), ft_strlcat()
#include <stdlib.h>	// NULL, malloc()

char	*ft_strjoin(char const *s1, char const *s2, _Bool is_path)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(s1_len + s2_len + 1 + is_path);
	if (new_str == NULL)
		ft_error(ERROR_MALLOC);
	ft_strncpy(new_str, s1, s1_len);
	if (is_path == 1)
		new_str[s1_len] = '/';
	ft_strncpy(new_str + s1_len + is_path, s2, s2_len);
	return (new_str);
}
