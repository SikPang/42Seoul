/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:24:23 by kwsong            #+#    #+#             */
/*   Updated: 2023/07/10 12:26:44 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Created.\n";
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other.type)
{
	std::cout << "WrongCat Created.\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	type = other.type;
	
	return *this;
}

WrongCat::~WrongCat() 
{
	std::cout << "WrongCat Destroyed.\n";
}

void WrongCat::makeSound() const
{
	std::cout << "* Meow~ *\n";
}