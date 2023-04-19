/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:56:35 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/19 16:58:57 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fixedPointNumber = 0;
}

Fixed::Fixed(const int value)
{
	fixedPointNumber = value;
}

Fixed::Fixed(const float value)
{
	float temp = value;
	int* a = (int*)&temp;
	fixedPointNumber = *a;
}

Fixed::Fixed(Fixed& instance)
{
	std::cout << "Copy constructor called\n";
	this->fixedPointNumber = instance.fixedPointNumber;
}

Fixed& Fixed::operator=(Fixed& instance)
{
	std::cout << "Copy assignment operator called\n";
	this->fixedPointNumber = instance.getRawBits();
	return *this;
}

Fixed& Fixed::operator<<(const float value)
{
	float temp = value;
	int* a = (int*)&temp;
	fixedPointNumber = *a;
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
	return (float)fixedPointNumber;
}

int Fixed::toInt( void ) const
{
	return (float)fixedPointNumber;
}