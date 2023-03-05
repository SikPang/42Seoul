/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:07:12 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/17 14:04:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
//     int c1 = 'a';
//     int c2 = '4';
//     int c3 = '!';
//     int c4 = 0;
//     int c5 = 127;
//     int c6 = 255;

//     printf("%d %d %d %d %d %d\n", ft_isprint(c1), ft_isprint(c2)
// 	, ft_isprint(c3), ft_isprint(c4), ft_isprint(c5), ft_isprint(c6));
//     printf("%d %d %d %d %d %d\n", isprint(c1), isprint(c2), isprint(c3)
// 	, isprint(c4), isprint(c5), isprint(c6));
// }
