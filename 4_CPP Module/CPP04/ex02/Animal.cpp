/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:54:41 by kwsong            #+#    #+#             */
/*   Updated: 2023/11/06 22:28:53 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	: type("some animal")
{
	std::cout << "Animal Created.\n";
}

Animal::Animal(const std::string& type)
	: type(type)
{
	std::cout << "Animal Created.\n";
}

Animal::Animal(const Animal& other)
	: type(other.type)
{
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

const std::string& Animal::getType() const
{
	return type;
}