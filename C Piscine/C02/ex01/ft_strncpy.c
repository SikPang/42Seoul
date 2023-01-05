/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:53:09 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/06 22:40:09 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (n == 0)
			return (dest);
		dest[i] = src[i];
		++i;
		--n;
	}
	while (n > 0)
	{
		dest[i] = '\0';
		++i;
		--n;
	}
	return (dest);
}
