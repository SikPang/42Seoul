/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <ccsa3321@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:54:44 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/20 10:25:19 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

unsigned int	ft_strlen(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_str_is_printable(char *str);
int				ft_str_is_numeric(char *str);

#endif
