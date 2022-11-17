/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:06:49 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/17 14:03:34 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
    int c1 = 'a';
    int c2 = 'h';
    int c3 = '4';
    int c4 = '!';

    printf("%d %d %d %d\n", ft_isalnum(c1), ft_isalnum(c2)
	, ft_isalnum(c3), ft_isalnum(c4));
    printf("%d %d %d %d\n", isalnum(c1), isalnum(c2), isalnum(c3)
	, isalnum(c4));
}
*/
