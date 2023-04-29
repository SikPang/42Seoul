/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:06:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 17:34:28 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain;

	std::cout << "Cat Created.\n";
}

Cat::Cat(const Cat& other)
{
	type = other.type;
	brain = new Brain;
	brain->duplicate(other.brain);

	std::cout << "Cat Created.\n";
}

Cat& Cat::operator=(const Cat& other)
{
	type = other.type;
	brain->duplicate(other.brain);
	
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

unsigned int Cat::GetSizeOfIdeas() const
{
	return brain->GetSize();
}

void Cat::AddIdea(const std::string& idea, unsigned int index)
{
	brain->AddIdea(idea, index);
}

std::string Cat::GetIdea(unsigned int index) const
{
	return brain->GetIdea(index);
}