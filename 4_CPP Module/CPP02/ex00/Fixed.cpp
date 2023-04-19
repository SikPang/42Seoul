/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:56:35 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/19 15:09:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fixedPointNumber = 0;
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