/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:03:06 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/26 15:43:23 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
	if (a >= b)
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