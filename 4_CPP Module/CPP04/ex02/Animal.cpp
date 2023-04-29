/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:54:41 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 17:44:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal()
{
	type = "some animal";

	std::cout << "Animal Created.\n";
}

Animal::Animal(const Animal& instance)
{
	type = instance.type;

	std::cout << "Animal Created.\n";
}

Animal& Animal::operator=(const Animal& instance)
{
	type = instance.type;
	
	return *this;
}

Animal::~Animal() 
{
	std::cout << "Animal Destroyed.\n";
}

std::string Animal::getType() const
{
	return type;
}