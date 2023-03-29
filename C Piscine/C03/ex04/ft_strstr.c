/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:13:42 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/10 18:21:54 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_equal(char *str, char *to_find, int i, int length)
{
	int	find_index;

	find_index = 0;
	while (to_find[find_index] != '\0' && str[i] == to_find[find_index])
	{
		++find_index;
		++i;
	}
	if (find_index == length)
		return (1);
	else
		return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	length;

	length = 0;
	while (to_find[length] != '\0')
		++length;
	if (length == 0)
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			if (check_equal(str, to_find, i, length))
				return (str + i);
		}
		++i;
	}
	return (0);
}
