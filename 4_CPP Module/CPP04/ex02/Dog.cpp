/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:06:36 by kwsong            #+#    #+#             */
/*   Updated: 2023/07/10 12:37:54 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: Animal("Dog")
	, brain(new Brain)
{
	std::cout << "Dog Created.\n";
}

Dog::Dog(const Dog& other)
	: Animal(other.type)
	, brain(other.brain)
{
	std::cout << "Dog Created.\n";
}

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return *this;

	type = other.type;
	*brain = *(other.brain);
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

void Dog::AddIdea(const std::string& idea, unsigned int index)
{
	brain->AddIdea(idea, index);
}

const std::string& Dog::GetIdea(unsigned int index) const
{
	return brain->GetIdea(index);
}