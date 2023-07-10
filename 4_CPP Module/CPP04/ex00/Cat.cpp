/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:06:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/07/10 12:26:02 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	: Animal("Cat")
{
	std::cout << "Cat Created.\n";
}

Cat::Cat(const Cat& other)
	: Animal(other.type)
{
	std::cout << "Cat Created.\n";
}

Cat& Cat::operator=(const Cat& other)
{
	type = other.type;
	
	return *this;
}

Cat::~Cat() 
{
	std::cout << "Cat Destroyed.\n";
}

void Cat::makeSound() const
{
	std::cout << "* Meow~ *\n";
}