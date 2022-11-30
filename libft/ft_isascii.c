/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:07:01 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/07 23:26:16 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
//     int c1 = 'a';
//     int c2 = 'H';
//     int c3 = '2';
//     int c4 = 0;
//     int c5 = 127;
//     int c6 = 128;

//     printf("%d %d %d %d %d %d\n", ft_isascii(c1), ft_isascii(c2)
//		, ft_isascii(c3), ft_isascii(c4), ft_isascii(c5), ft_isascii(c6));
//     printf("%d %d %d %d %d %d\n", isascii(c1), isascii(c2), isascii(c3)
//		, isascii(c4), isascii(c5), isascii(c6));
// }