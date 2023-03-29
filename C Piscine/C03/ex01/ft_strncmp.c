/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:05:26 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/11 16:47:17 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (n == 0)
			return (0);
		if (s1[i] != s2[i])
			break ;
		++i;
		--n;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
