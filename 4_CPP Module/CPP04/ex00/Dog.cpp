/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:06:36 by kwsong            #+#    #+#             */
/*   Updated: 2023/07/10 12:26:08 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: Animal("Dog")
{
	std::cout << "Dog Created.\n";
}

Dog::Dog(const Dog& other)
	: Animal(other.type)
{
	std::cout << "Dog Created.\n";
}

Dog& Dog::operator=(const Dog& other)
{
	type = other.type;
	
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