/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:06:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 19:38:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";

	std::cout << "Cat Created.\n";
}

Cat::Cat(const Cat& other)
{
	type = other.type;

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