/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:59:27 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 15:15:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
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
// 	printf("%c %c %c %c %c\n", ft_tolower(c1),  ft_tolower(c2)
// 		, ft_tolower(c3), ft_tolower(c4), ft_tolower(c5));
// 	printf("%c %c %c %c %c\n", tolower(c1),  tolower(c2)
// 		, tolower(c3), tolower(c4), tolower(c5));
// }