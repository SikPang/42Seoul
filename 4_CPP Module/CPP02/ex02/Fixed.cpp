/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:56:35 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 19:26:43 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
	: fixedPointNumber(0)
{
}

Fixed::Fixed(const Fixed& other)
	: fixedPointNumber(other.fixedPointNumber)
{
}

Fixed::Fixed(const int value)
{
	fixedPointNumber = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	fixedPointNumber = (int)roundf(value * (1 << fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	this->fixedPointNumber = other.fixedPointNumber;
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return fixedPointNumber;
}

void Fixed::setRawBits(int const raw)
{
	fixedPointNumber = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)fixedPointNumber / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
	return fixedPointNumber >> fractionalBits;
}

Fixed Fixed::operator++(int) 
{
	Fixed temp(*this);
	++this->fixedPointNumber;
	return temp;
};

Fixed Fixed::operator--(int) 
{
	Fixed temp(*this);
	--this->fixedPointNumber;
	return temp;
};

std::ostream& operator<<(std::ostream& os, const Fixed& value)
{
	os << value.toFloat();
	return (os);
}