/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:51:59 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/02 22:09:31 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>


// void	ft_strncpy(char *dest, char *src, size_t start_index, size_t n)
// {
// 	size_t	i;

// 	if (src == 0)
// 		return ;
// 	i = 0;
// 	while (n > 0)
// 	{
// 		dest[i + start_index] = src[i];
// 		++i;
// 		--n;
// 	}
// 	dest[i + start_index] = '\0';
// 	return ;
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		++i;
// 	}
// 	return (i);
// }

// char	*ft_substr(char const *s, size_t start, size_t len)
// {
// 	char	*new_str;
// 	size_t	s_len;
// 	size_t	i;

// 	s_len = ft_strlen(s);
// 	if (s_len <= start)
// 	{
// 		new_str = (char *)malloc(1);
// 		new_str[0] = '\0';
// 		return (new_str);
// 	}
// 	if (s_len - start < len)
// 		len = s_len - start;
// 	new_str = (char *)malloc((len + 1) * sizeof(char));
// 	new_str[len] = '\0';
// 	if (new_str == (char *)0)
// 		return ((char *)0);
// 	i = 0;
// 	while (i < len)
// 	{
// 		new_str[i] = s[i + start];
// 		++i;
// 	}
// 	return (new_str);
// }




char	*get_result(char **total, ssize_t found_index)
{
	char	*temp;
	char	*result;

	temp = *total;
	result = ft_substr(*total, 0, found_index + 1);
	if (result == 0)
		return (0);
	*total = ft_substr(*total, found_index + 1, ft_strlen(*total) - (found_index + 1));
	if (*total == 0)
	{
		free(result);
		free(temp);
		return (0);
	}
	free(temp);
	return (result);
}

int	add_to_total(char **total, char *buf, ssize_t buf_len)
{
	char	*temp;
	size_t	total_len;
	size_t	i;

	i = 0;
	total_len = 0;
	if (*total != 0)
		total_len = ft_strlen(*total);
	temp = *total;
	*total = (char *)malloc(total_len + buf_len + 1);
	if (*total == 0)
	{
		free(temp);
		return (0);
	}
	ft_strncpy(*total, temp, 0, total_len);
	ft_strncpy(*total, buf, total_len, buf_len);
	free(temp);
	return (1);
}

ssize_t	check_new_line(char *total)
{
	ssize_t	i;

	if (total == 0)
		return (-1);
	i = 0; 
	while (total[i] != '\0')
	{
		if (total[i] == '\n')
			return (i);
		++i;
	}
	if (i == 0)
		return (-2);
	else
		return (-3);
}

char	*get_next_line(int fd)
{
	static char	*total;
	char		buf[BUFFER_SIZE];
	ssize_t		check_finish;
	ssize_t		check_read;

	check_read = BUFFER_SIZE;
	while (1)
	{
		check_finish = check_new_line(total);
		if (check_finish >= 0 || check_read < BUFFER_SIZE)
			break ;
		check_read = read(fd, buf, BUFFER_SIZE);
		if (check_read == -1
			|| (check_read == 0 && (check_finish == -2 || check_finish == -1)))
			return (0);
		if (buf[0] != '\0')
			add_to_total(&total, buf, check_read);
	}
	return (get_result(&total, check_finish));
}

/*
check_new_line 함수
- 널 포인터일 경우, return -1
- 빈 문자열일 경우, return -2
- 못 찾았을 경우, return -3
- 개행을 찾았을 경우, return index (0 이상)
*/

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

// void print_line(int fd)
// {
// 	char *str = get_next_line(fd);
// 	printf("return : %s\n-------- \n", str);
// 	free(str);
// }

// static void foo()
// {
// 	static void* f;
// 	void* ff = malloc(123);
// 	f = ff;
// }

// int main()
// {
// 	foo(); foo(); foo();
// 	while (1)
// 	{
		
// 	}
// 	// int fd = open("t_hello.txt", O_RDONLY);
// 	// printf("fd = %d\n", fd);

// 	// print_line(fd);
// 	// print_line(fd);
// 	// print_line(fd);
// 	// print_line(fd);
// 	// print_line(fd);

// 	// print_line(fd);
// 	// print_line(fd);
// 	// print_line(fd);
// 	// print_line(fd);
// 	// print_line(fd);
// }