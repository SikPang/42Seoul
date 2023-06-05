/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:03:06 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/05 12:56:30 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void print(const T& data)
{
	std::cout << data << " ";
}

template <typename T>
void iter(T* arr, unsigned int len, void (*func)(const T&))
{
	for (unsigned int i=0; i<len; ++i)
		func(arr[i]);
}