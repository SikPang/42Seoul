/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/26 15:54:41 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main()
{
	int a = 2;
	int b = 3;
	std::cout << "before : a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "after : a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << (::min( a, b ) < ::max( a, b )) << std::endl;
	std::cout << (::min( a, b ) > ::max( a, b )) << std::endl;
	std::cout << (::min( a, b ) == ::max( a, b )) << std::endl;
	std::cout << (::min( a, b ) <= ::max( a, b )) << std::endl;
	std::cout << (::min( a, b ) >= ::max( a, b )) << std::endl << std::endl;;

	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "before : c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "after : c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << (::min( c, d ) < ::max( c, d )) << std::endl;
	std::cout << (::min( c, d ) > ::max( c, d )) << std::endl;
	std::cout << (::min( c, d ) == ::max( c, d )) << std::endl;
	std::cout << (::min( c, d ) <= ::max( c, d )) << std::endl;
	std::cout << (::min( c, d ) >= ::max( c, d )) << std::endl << std::endl;;
	
	float e = 1.2;
	float f = 3.4;
	std::cout << "before : e = " << e << ", f = " << f << std::endl;
	::swap( e, f );
	std::cout << "after : e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl << std::endl;
	
	long g = 9999999999999999;
	long h = -9999999999999999;
	std::cout << "before : g = " << g << ", h = " << h << std::endl;
	::swap( g, h );
	std::cout << "after : g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl << std::endl;
	return 0;
}