/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:50:20 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/11 09:08:38 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (dest[length] != '\0')
		++length;
	while (src[i] != '\0')
	{
		dest[length] = src[i];
		++length;
		++i;
	}
	dest[length] = '\0';
	return (dest);
}
