/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:54:41 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 19:38:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal()
{
	type = "some animal";

	std::cout << "Animal Created.\n";
}

Animal::Animal(const Animal& other)
{
	type = other.type;

	std::cout << "Animal Created.\n";
}

Animal& Animal::operator=(const Animal& other)
{
	type = other.type;
	
	return *this;
}

Animal::~Animal() 
{
	std::cout << "Animal Destroyed.\n";
}

void Animal::makeSound() const
{
	std::cout << "* some animal's sound *\n";
}

std::string Animal::getType() const
{
	return type;
}