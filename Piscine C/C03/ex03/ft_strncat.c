/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:54:10 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/11 11:42:30 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	length;
	unsigned int	i;

	length = 0;
	i = 0;
	while (dest[length] != '\0')
		++length;
	while (src[i] != '\0')
	{
		if (nb == 0)
			break ;
		dest[length] = src[i];
		++length;
		++i;
		--nb;
	}
	dest[length] = '\0';
	return (dest);
}
