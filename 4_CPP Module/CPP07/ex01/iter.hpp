/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:03:06 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/26 15:52:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void print(T data)
{
	std::cout << data << " ";
}

template <typename T>
void iter(T* arr, unsigned int len, void (*func)(T))
{
	for (unsigned int i=0; i<len; ++i)
		func(arr[i]);
}