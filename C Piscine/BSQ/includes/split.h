/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:39:23 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/20 10:14:34 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

# include <stdlib.h>

void	init_space(int *is_space);
char	*pm_dup(char *str, int size, int i);
void	count_col(char *str, int *is_space, char *arr[], int i);
int		count_row(char *str, int *is_space);
char	**split(char *str, int *length);

#endif
