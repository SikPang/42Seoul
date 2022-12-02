/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:51:59 by kwsong            #+#    #+#             */
/*   Updated: 2022/12/02 16:29:34 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*get_result(char **result, char **total, ssize_t found_index)
{
	char	*temp;

	temp = *total;
	*result = ft_substr(*total, 0, found_index + 1);
	if (*result == 0)
		return (0);
	*total = ft_substr(*total, found_index + 1,
			ft_strlen(*total) - found_index + 1);
	if (*total == 0)
		return (0);
	free(temp);
	return (*result);
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
		return (0);
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
	char		*result;
	char		buf[BUFFER_SIZE];
	ssize_t		check_finish;
	ssize_t		check_read;

	check_read = BUFFER_SIZE;
	while (1)
	{
		check_finish = check_new_line(total);
		if (check_finish >= 0 || check_read < BUFFER_SIZE)
		{
			result = get_result(&result, &total, check_finish);
			if (result == 0)
				return (0);
			break ;
		}
		check_read = read(fd, buf, BUFFER_SIZE);
		if (check_read == -1
			|| (check_read == 0 && (check_finish == -2 || check_finish == -1)))
			return (0);
		if (buf[0] != '\0')
			add_to_total(&total, buf, check_read);
	}
	return (result);
}

/*
check_new_line 함수
- 널 포인터일 경우, return -1
- 빈 문자열일 경우, return -2
- 못 찾았을 경우, return -3
- 개행을 찾았을 경우, return index (0 이상)
*/

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int fd = open("t_hello.txt", O_RDONLY);

// 	printf("%d\n", fd);
// 	printf("return : %s\n", get_next_line(fd));	// hello
// 	printf("return : %s\n", get_next_line(fd));	// world
// 	printf("return : %s\n", get_next_line(fd));	// my
// 	printf("return : %s\n", get_next_line(fd));	// name
// 	printf("return : %s\n", get_next_line(fd));	// is
// 	printf("return : %s\n", get_next_line(fd));	// kwsong
// 	printf("return : %s\n", get_next_line(fd));	// ^_^

// 	printf("return : %s\n", get_next_line(fd));	// (null)
// 	printf("return : %s\n", get_next_line(fd));	// (null)
// 	printf("return : %s\n", get_next_line(fd));	// (null)
// }
