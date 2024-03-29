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
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other)
	: fixedPointNumber(other.fixedPointNumber)
{
	std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	fixedPointNumber = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	fixedPointNumber = (int)roundf(value * (1 << fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	this->fixedPointNumber = other.fixedPointNumber;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
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

std::ostream& operator<<(std::ostream& os, const Fixed& value)
{
	os << value.toFloat();
	return (os);
}