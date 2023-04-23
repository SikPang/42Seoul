/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:55:57 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 19:14:01 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "max : " << Fixed::max( a, b ) << std::endl;
	std::cout << "min : " << Fixed::min( a, b ) << std::endl;
	
	std::cout << '\n';
	std::cout << "+ : " << std::setw(10) << a + b << ", " << std::setw(10) << a << ", " << std::setw(10) << b << '\n';
	std::cout << "- : " << std::setw(10) << a - b << ", " << std::setw(10) << a << ", " << std::setw(10) << b << '\n';
	std::cout << "* : " << std::setw(10) << a * b << ", " << std::setw(10) << a << ", " << std::setw(10) << b << '\n';
	std::cout << "/ : " << std::setw(10) << a / b << ", " << std::setw(10) << a << ", " << std::setw(10) << b << '\n';

	std::cout << '\n';
	std::cout << ">  : " << std::setw(10) << (a > b) << ", " << std::setw(10) << a << ", " << std::setw(10) << b << '\n';
	std::cout << "<  : " << std::setw(10) << (a < b) << ", " << std::setw(10) << a << ", " << std::setw(10) << b << '\n';
	std::cout << "== : " << std::setw(10) << (a == b) << ", " << std::setw(10) << a << ", " << std::setw(10) << b << '\n';
	std::cout << "!= : " << std::setw(10) << (a != b) << ", " << std::setw(10) << a << ", " << std::setw(10) << b << '\n';

	Fixed c(3.14f);
	Fixed d(3.14f);

	std::cout << '\n';
	std::cout << ">= : " << std::setw(10) << (c >= d) << '\n';
	std::cout << "<= : " << std::setw(10) << (c <= d) << '\n';
	std::cout << "== : " << std::setw(10) << (c == d) << '\n';
	std::cout << "!= : " << std::setw(10) << (c != d) << '\n';

	std::cout << "max : " << Fixed::max( c, d ) << std::endl;
	std::cout << "min : " << Fixed::min( c, d ) << std::endl;

	return 0;
}