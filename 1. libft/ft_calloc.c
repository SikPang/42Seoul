/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:34:02 by kwsong            #+#    #+#             */
/*   Updated: 2022/11/10 13:14:02 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*new_mem;
	size_t	i;

	if (nelem <= 0 || elsize <= 0)
		return ((void *)0);
	new_mem = malloc(elsize * nelem);
	if (new_mem == (void *)0)
		return ((void *)0);
	i = 0;
	while (i < nelem)
	{
		((unsigned char *)new_mem)[i] = 0;
		++i;
	}
	return (new_mem);
}

// #include <stdio.h>
// int main()
// {
// 	int size = 10;
// 	int *mem1 = (int *)ft_calloc(size, sizeof(int));
// 	int *mem2 = (int *)calloc(size, sizeof(int));
// 	char *mem3 = (char *)ft_calloc(size, sizeof(char));
// 	char *mem4 = (char *)calloc(size, sizeof(char));
	
// 	for (int i=0; i<size; ++i)
// 		printf("%d", mem1[i]);
// 	printf("\n");
// 	for (int i=0; i<size; ++i)
// 		printf("%d", mem2[i]);
// }