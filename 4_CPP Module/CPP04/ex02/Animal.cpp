/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:54:41 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 19:46:12 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal()
{
	type = "some animal";
	brain = new Brain();

	std::cout << "Animal Created.\n";
}

Animal::Animal(Animal& instance)
{
	instance.type = type;
	brain = instance.brain;

	std::cout << "Animal Created.\n";
}

Animal& Animal::operator=(Animal& instance)
{
	instance.type = type;
	brain = instance.brain;
	
	return *this;
}

Animal::~Animal() 
{
	delete brain;
	std::cout << "Animal Destroyed.\n";
}

std::string Animal::getType() const
{
	return type;
}