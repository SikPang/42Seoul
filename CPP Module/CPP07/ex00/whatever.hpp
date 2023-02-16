/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:03:06 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 20:26:33 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

template <typename T>
void swap(T& a, T& b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b)
{
	if (a > b)
		return b;
	else
		return a;
}

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif