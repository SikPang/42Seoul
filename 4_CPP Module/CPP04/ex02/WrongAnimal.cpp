/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:23:35 by kwsong            #+#    #+#             */
/*   Updated: 2023/07/10 12:23:40 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("some WrongAnimal")
{
	std::cout << "WrongAnimal Created.\n";
}

WrongAnimal::WrongAnimal(const std::string& type)
	: type(type)
{
	std::cout << "WrongAnimal Created.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	: type(other.type)
{
	std::cout << "WrongAnimal Created.\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	type = other.type;
	
	return *this;
}

WrongAnimal::~WrongAnimal() 
{
	std::cout << "WrongAnimal Destroyed.\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "* some WrongAnimal's sound *\n";
}

const std::string& WrongAnimal::getType() const
{
	return type;
}