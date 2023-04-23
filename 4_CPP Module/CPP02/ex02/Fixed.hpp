/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:56:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 19:23:11 by kwsong           ###   ########.fr       */
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
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed();

public:
	Fixed&	operator=(const Fixed& other);
	inline bool	operator>(const Fixed& other) { return this->fixedPointNumber > other.fixedPointNumber; };
	inline bool	operator<(const Fixed& other) { return this->fixedPointNumber < other.fixedPointNumber; };
	inline bool	operator>=(const Fixed& other) { return this->fixedPointNumber >= other.fixedPointNumber; };
	inline bool	operator<=(const Fixed& other) { return this->fixedPointNumber <= other.fixedPointNumber; };
	inline bool	operator==(const Fixed& other) { return this->fixedPointNumber == other.fixedPointNumber; };
	inline bool	operator!=(const Fixed& other) { return this->fixedPointNumber != other.fixedPointNumber; };
	inline Fixed	operator+(const Fixed& other) { return Fixed(this->toFloat() + other.toFloat()); };
	inline Fixed	operator-(const Fixed& other) { return Fixed(this->toFloat() - other.toFloat()); };
	inline Fixed	operator*(const Fixed& other) { return Fixed(this->toFloat() * other.toFloat()); };
	inline Fixed	operator/(const Fixed& other) { return Fixed(this->toFloat() / other.toFloat()); };
	inline Fixed&	operator++() { ++this->fixedPointNumber; return *this; };
	inline Fixed&	operator--() { --this->fixedPointNumber; return *this; };
	Fixed	operator++(int);
	Fixed	operator--(int);

public:
	int		getRawBits( void ) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
	
public:
	inline static Fixed&		min(Fixed& f1, Fixed& f2) { return (f1.fixedPointNumber  < f2.fixedPointNumber) ? f1 : f2; };
	inline static const Fixed&	min(const Fixed& f1, const Fixed& f2) { return (f1.fixedPointNumber  < f2.fixedPointNumber) ? f1 : f2; };
	inline static Fixed&		max(Fixed& f1, Fixed& f2) { return (f1.fixedPointNumber  > f2.fixedPointNumber) ? f1 : f2; };
	inline static const Fixed&	max(const Fixed& f1, const Fixed& f2) { return (f1.fixedPointNumber  > f2.fixedPointNumber) ? f1 : f2; };
};

std::ostream& operator<<(std::ostream& os, const Fixed& value);

#endif