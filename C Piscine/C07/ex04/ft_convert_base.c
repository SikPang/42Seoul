/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:42:34 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/17 16:58:35 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_length(long long lnb, int to_len);
void	finish_answer(char *base_to, char *answer, long long nb, int to_len);
void	initialize(char *arr, long long nb, int to_len);
void	init_minus(int *minus, int lnb);

void	set_nbr(long long nb, int base_length, int depth, char *answer)
{
	if (nb < base_length)
	{
		answer[depth - 1] = nb;
		return ;
	}
	set_nbr(nb / base_length, base_length, depth - 1, answer);
	answer[depth - 1] = nb % base_length;
}

int	check_base(char *base, int *base_length)
{
	int	is_duplicated[128];
	int	i;

	i = 0;
	while (i < 128)
		is_duplicated[i++] = 0;
	*base_length = 0;
	while (base[*base_length] != '\0')
	{
		if (is_duplicated[(int)base[*base_length]] == 1)
			return (0);
		else
			is_duplicated[(int)base[*base_length]] = 1;
		if (base[*base_length] == '+' || base[*base_length] == '-'
			|| base[*base_length] == ' ' || (base[*base_length] >= 9
				&& base[*base_length] <= 13))
			return (0);
		++(*base_length);
	}
	if (base[0] == '\0' || *base_length == 1)
		return (0);
	return (1);
}

int	check_str_is_base(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (ch == base[i])
			return (i);
		++i;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	minus;
	int	base_length;
	int	num;

	num = 0;
	minus = 1;
	if (check_base(base, &base_length) == 0)
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		++i;
	}
	while (check_str_is_base(str[i], base) != -1)
	{
		num = num * base_length + check_str_is_base(str[i], base);
		++i;
	}
	return (num * minus);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			from_len;
	int			to_len;
	char		*answer;
	long long	lnb;
	int			minus;

	if (!check_base(base_from, &from_len) || !check_base(base_to, &to_len))
		return (0);
	lnb = (long long)ft_atoi_base(nbr, base_from);
	answer = (char *)malloc(sizeof(char) * (get_length(lnb, to_len) + 1));
	init_minus(&minus, lnb);
	if (answer == 0)
		return (0);
	initialize(answer, lnb, to_len);
	if (lnb < 0)
	{
		answer[0] = '-';
		++answer;
		lnb *= -1;
	}
	set_nbr(lnb, to_len, get_length(lnb, to_len), answer);
	finish_answer(base_to, answer, lnb, to_len);
	if (minus == 1)
		--answer;
	return (answer);
}
