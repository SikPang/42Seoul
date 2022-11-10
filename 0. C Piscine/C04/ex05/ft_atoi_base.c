/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:34:31 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/15 20:15:35 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_index(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (ch == base[i])
			return (i);
		++i;
	}
	return (0);
}

int	check_str_is_base(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (ch == base[i])
			return (1);
		++i;
	}
	return (0);
}

int	calculate_minus(char *str, int i, int *minus)
{
	int	count;

	count = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			++count;
		++i;
	}
	if (count % 2 == 1)
		*minus = -1;
	else
		*minus = 1;
	return (i);
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	minus;
	int	base_length;
	int	num;

	num = 0;
	if (check_base(base, &base_length) == 0)
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	i = calculate_minus(str, i, &minus);
	while (check_str_is_base(str[i], base) == 1)
	{
		num *= base_length;
		num += get_index(str[i], base);
		++i;
	}
	return (num * minus);
}
