/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:56:55 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/17 16:58:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	get_length(long long lnb, int to_len)
{
	int	i;

	if (lnb < 0)
		i = 1;
	else
		i = 0;
	while (lnb != 0)
	{
		lnb /= to_len;
		++i;
	}
	if (i == 0)
		return (1);
	return (i);
}

void	finish_answer(char *base_to, char *answer, long long nb, int to_len)
{
	int	i;

	i = 0;
	while (i < get_length(nb, to_len))
	{
		answer[i] = base_to[(int)answer[i]];
		++i;
	}
	answer[i] = 0;
}

void	initialize(char *arr, long long nb, int to_len)
{
	int	i;

	i = 0;
	while (i < get_length(nb, to_len) + 2)
	{
		arr[i] = '\0';
		++i;
	}
}

void	init_minus(int *minus, int lnb)
{
	if (lnb < 0)
		*minus = 1;
	else
		*minus = 0;
}
