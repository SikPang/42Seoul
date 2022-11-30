/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:55:46 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 15:15:08 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// int main()
// {
// 	int c1 = 'a';
// 	int c2 = 'z';
// 	int c3 = 'A';
// 	int c4 = 'Z';
// 	int c5 = '!';
// 	printf("%c %c %c %c %c\n", ft_toupper(c1),  ft_toupper(c2)
// 		, ft_toupper(c3), ft_toupper(c4), ft_toupper(c5));
// 	printf("%c %c %c %c %c\n", toupper(c1),  toupper(c2)
// 		, toupper(c3), toupper(c4), toupper(c5));
// }