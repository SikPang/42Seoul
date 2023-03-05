/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:03:06 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 20:33:41 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ITER_HPP__
#define __ITER_HPP__

template <typename T>
void temp(T data)
{
	(void)data;
}

template <typename T>
void iter(T* arr, unsigned int len, void (*func)(T))
{
	for (int i=0; i<len; ++i)
		func(arr[i]);
}

#endif