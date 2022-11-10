/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:13:13 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/13 17:35:52 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		++i;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	sort_params(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	while (j < argc)
	{
		i = 0;
		while (i < argc - 1 - j)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
			}
			++i;
		}
		++j;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;

	sort_params(argc - 1, argv + 1);
	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			write(1, &argv[j][i], 1);
			++i;
		}
		write(1, "\n", 1);
		++j;
	}
	return (0);
}
