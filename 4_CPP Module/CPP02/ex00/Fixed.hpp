/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:56:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 19:25:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed
{
private:
	int	fixedPointNumber;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed& other);
	~Fixed();
	Fixed&	operator=(const Fixed& other);

public:
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif