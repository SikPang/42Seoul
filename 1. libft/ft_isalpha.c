/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:06:56 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/17 14:03:46 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
//     int c3 = '2';

//     printf("%d %d %d\n", ft_isalpha(c1), ft_isalpha(c2), ft_isalpha(c3));
//     printf("%d %d %d\n", isalpha(c1), isalpha(c2), isalpha(c3));
// }
