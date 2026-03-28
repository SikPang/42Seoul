/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:28:38 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 10:47:44 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include <stdlib.h>	//NULL, malloc(), free()
# include "ft_str.h"
# include "ft_atoi.h"
# include "map.h"
# include "pm_mem.h"	//check_null_after_malloc(), occur_error()
# include "pm_file.h"

// NULL (error), t_map* (else)
t_map	*parsing_map(char *file_name);

#endif
