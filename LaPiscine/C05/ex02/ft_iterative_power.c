/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:36:35 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/12 15:25:28 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	num;

	if (power < 0)
		return (0);
	num = 1;
	while (power != 0)
	{
		num *= nb;
		--power;
	}
	return (num);
}
