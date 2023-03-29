/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:35:49 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/11 16:29:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_length(char *arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i] != '\0')
		++i;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_length;
	unsigned int	src_length;
	unsigned int	i;
	unsigned int	j;

	dest_length = get_length(dest);
	src_length = get_length(src);
	if (size < dest_length)
		return (size + src_length);
	i = 0;
	j = dest_length;
	size -= dest_length;
	while (src[i] != '\0')
	{
		if (size <= 1)
			break ;
		dest[j] = src[i];
		++j;
		++i;
		--size;
	}
	dest[j] = '\0';
	return (dest_length + src_length);
}
