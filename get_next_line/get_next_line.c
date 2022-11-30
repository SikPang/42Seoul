/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:51:59 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/30 21:50:00 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

size_t	check_new_line(char *total)
{
	size_t	i;

	if (total == 0)
		return (-1);		// 널 포인터일 경우, return -1
	i = 0;
	while (total[i]!= '\0')
	{
		if (total[i] == '\n')
			return (i);		// 개행을 찾았을 경우, return index (0 이상)
		++i;
	}
	if (i == 0)
		return (-2);		// 빈 문자열일 경우, return -2
	else
		return (-3);		// 못 찾았을 경우, return -3
}

char	*get_result(char **result, char **total, size_t check)
{
	char	*temp;
	
	temp = *total;
	*result = ft_substr(*total, 0, check);
	if (*result == 0)
		return (0);
	*total = ft_substr(*total, check, ft_strlen(*total));
	if (*total == 0)
		return (0);
	free(temp);
	return (*result);
}

char	*get_next_line(int fd)
{
	static char	*total;
	char		*result;
	char		buf[BUFFER_SIZE];
	size_t		check;

	while (fd < 0)
	{
		check = check_new_line(total);
		if (check >= 0)		// index가 return될 시, index부터 끝까지 길이로 substr 후 return
		{
			result = get_result(&result, &total, check);
			if (result == 0)
				return (0);
			break ;
		}
		// 일단 음수는 모두 반복문 다시 돌게 함, -2는 고려해볼 것
		fd = read(fd, buf, BUFFER_SIZE);
		
	}

	return (result);
}



// #include <string.h>
// char	*get_next_line(int fd)
// {
// 	static char	*total;	// 동적 할당?
// 	char		buf[BUFFER_SIZE];
// 	char		*new;
// 	size_t		byte;
// 	size_t		temp;

// 	byte = 0;
// 	while (fd > 2)	// 파일 끝까지 갔거나, 개행 문자를 찾기 전까지
// 	{
// 		temp = check_new_line(buf);
// 		if (temp == 0)
// 			return (0);
// 		else if (temp > 0)
// 		{
// 			new = ft_substr(buf, 0, temp - 1);
// 			if (new == 0)
// 				return (0);
// 			break ;
// 		}
// 		fd = read(fd, buf, BUFFER_SIZE);
// 		byte += temp;
// 	}
// 	return (strdup(buf));
// }



// #include <string.h>
// char	*get_next_line(int fd)
// {
// 	char	buf[BUFFER_SIZE];
	
// 	fd = read(fd, buf, BUFFER_SIZE);
// 	return (strdup(buf));
// }