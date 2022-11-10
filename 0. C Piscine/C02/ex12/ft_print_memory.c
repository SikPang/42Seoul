/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:08:08 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/08 09:52:52 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_space(int i)
{
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		++i;
	}
}

void	print_address(unsigned long long addr, unsigned int start_index)
{
	unsigned long long	num;
	char				*hex;
	char				arr[16];
	int					i;

	num = addr + start_index;
	hex = "0123456789abcdef";
	i = 0;
	while (i < 16)
		arr[i++] = '0';
	while (num != 0)
	{
		arr[--i] = hex[(int)(num % 16)];
		num /= 16;
	}
	write(1, arr, 16);
	write(1, ": ", 2);
}

void	print_string(char *addr, unsigned int start_index
		, unsigned int end_index)
{
	unsigned int	i;

	i = start_index;
	while (i < end_index)
	{
		if (addr[i] < 32 || addr[i] == 127)
			write(1, ".", 1);
		else
			write(1, &addr[i], 1);
		++i;
	}
}

void	print_string_to_hex(unsigned char *addr, unsigned int start_index
		, unsigned int end_index)
{
	int				temp;
	unsigned int	i;
	char			*hex;
	unsigned int	check;

	i = start_index;
	hex = "0123456789abcdef";
	if (end_index - start_index == 16)
		check = 0;
	else
		check = 1;
	while (i < end_index)
	{
		temp = addr[i];
		write(1, &hex[addr[i] / 16], 1);
		write(1, &hex[addr[i] % 16], 1);
		++i;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
	if (check == 1)
		print_space(i % 16);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	start_index;
	unsigned int	end_index;

	start_index = 0;
	end_index = 0;
	if (size == 0)
		return (addr);
	while (1)
	{
		if (size / 16 != 0)
			end_index += 16;
		else
			end_index += size;
		print_address((unsigned long long)addr, start_index);
		print_string_to_hex((unsigned char *)addr, start_index, end_index);
		print_string((char *)addr, start_index, end_index);
		write(1, "\n", 1);
		start_index += 16;
		if (size <= 16)
			break ;
		size -= 16;
	}
	return (addr);
}
