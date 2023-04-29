/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:06:36 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 17:34:28 by kwsong           ###   ########.fr       */
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

Dog::Dog(const Dog& other)
{
	type = other.type;
	brain = new Brain;
	brain->duplicate(other.brain);
	
	std::cout << "Dog Created.\n";
}

Dog& Dog::operator=(const Dog& other)
{
	type = other.type;
	brain->duplicate(other.brain);
	
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

unsigned int Dog::GetSizeOfIdeas() const
{
	return brain->GetSize();
}

void Dog::AddIdea(const std::string& idea, unsigned int index)
{
	brain->AddIdea(idea, index);
}

std::string Dog::GetIdea(unsigned int index) const
{
	return brain->GetIdea(index);
}