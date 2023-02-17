/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastAndPrint.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:54:53 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/17 17:33:47 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CASTANDPRINT_HPP__
#define __CASTANDPRINT_HPP__

#include <iostream>

template <typename T>
void CastAndPrint(T data)
{
	std::cout << "char   : " << static_cast<char>(data) << "\n";
	std::cout << "int    : "<< static_cast<int>(data) << "\n";
	std::cout << "float  : "<< static_cast<float>(data) << "\n";
	std::cout << "double : "<< static_cast<double>(data) << "\n";
}

#endif