/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 08:25:29 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/06 21:05:46 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (src[i++] != '\0')
		++count;
	if (size == 0)
		return (count);
	i = 0;
	while (src[i] != '\0')
	{
		if (size == 1)
		{
			dest[i] = '\0';
			break ;
		}
		dest[i] = src[i];
		++i;
		--size;
	}
	if (dest[i] != '\0')
		dest[i] = '\0';
	return (count);
}
