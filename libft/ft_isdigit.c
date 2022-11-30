/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:07:08 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/17 14:04:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
//     int c1 = 'a';
//     int c2 = 'h';
//     int c3 = '4';

//     printf("%d %d %d\n", ft_isdigit(c1), ft_isdigit(c2), ft_isdigit(c3));
//     printf("%d %d %d\n", isdigit(c1), isdigit(c2), isdigit(c3));
// }
