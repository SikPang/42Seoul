/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:00:00 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/12 14:10:48 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	answer;

	if (nb < 0)
		return (0);
	i = 0;
	answer = 1;
	while (nb != 0)
	{
		answer *= nb;
		--nb;
	}
	return (answer);
}
