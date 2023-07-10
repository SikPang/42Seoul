/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:06:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/07/10 12:46:47 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	: Animal("Cat")
	, brain(new Brain)
{
	std::cout << "Cat Created.\n";
}

Cat::Cat(const Cat& other)
	: Animal(other.type)
	, brain(other.brain)
{
	std::cout << "Cat Created.\n";
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return *this;

	type = other.type;
	*brain = *(other.brain);
	return *this;
}

Cat::~Cat() 
{
	delete brain;
	std::cout << "Cat Destroyed.\n";
}

void Cat::makeSound() const
{
	std::cout << "* Meow~ *\n";
}

void Cat::AddIdea(const std::string& idea, unsigned int index)
{
	brain->AddIdea(idea, index);
}

const std::string& Cat::GetIdea(unsigned int index) const
{
	return brain->GetIdea(index);
}