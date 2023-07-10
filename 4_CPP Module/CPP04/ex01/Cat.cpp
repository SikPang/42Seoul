/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:06:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/07/10 12:30:49 by kwsong           ###   ########.fr       */
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
	brain = other.brain;
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