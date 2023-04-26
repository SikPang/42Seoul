/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:06:36 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/26 21:25:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain;

	std::cout << "Dog Created.\n";
}

Dog::Dog(const Dog& instance)
{
	type = instance.type;
	brain = instance.brain;
	
	std::cout << "Dog Created.\n";
}

Dog& Dog::operator=(const Dog& instance)
{
	type = instance.type;
	brain = instance.brain;
	
	return *this;
}

Dog::~Dog() 
{
	delete brain;
	
	std::cout << "Dog Destroyed.\n";
}

void Dog::makeSound() const
{
	std::cout << "* Woof! *\n";
}