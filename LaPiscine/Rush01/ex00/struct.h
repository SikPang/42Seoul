/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 08:22:39 by kwsong            #+#    #+#             */
/*   Updated: 2022/10/09 22:37:52 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_set
{
	int	case_count;
	int	arr[4][24][4];
	int	temp[4];
	int	temp_ver[4][4];
	int	num[4][4];
	int	visited[4];
	int	answer[4][4];
}				t_set;

#endif
