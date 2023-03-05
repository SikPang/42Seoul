/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:06:36 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 18:35:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";

	std::cout << "Dog Created.\n";
}

Dog::Dog(Dog& instance)
{
	instance.type = type;

	std::cout << "Dog Created.\n";
}

Dog& Dog::operator=(Dog& instance)
{
	instance.type = type;
	
	return *this;
}

Dog::~Dog() 
{
	std::cout << "Dog Destroyed.\n";
}

void Dog::makeSound() const
{
	std::cout << "* Woof! *\n";
}