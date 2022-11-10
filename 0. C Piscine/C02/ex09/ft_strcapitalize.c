/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:31:51 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/07 08:24:39 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcapitalize(char *str)
{
	int	i;
	int	check_start;

	i = 0;
	check_start = 1;
	while (str[i] != '\0')
	{
		if (check_start == 0 && (str[i] < '0' || str[i] > '9')
			&& (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
			check_start = 1;
		if (check_start == 0 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		else if (check_start == 1 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			check_start = 0;
		}
		else if (check_start == 1 && ((str[i] >= '0' && str[i] <= '9')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
			check_start = 0;
		++i;
	}
	return (str);
}
