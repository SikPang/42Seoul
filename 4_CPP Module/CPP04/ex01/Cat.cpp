/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:06:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/26 21:24:48 by kwsong           ###   ########.fr       */
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

Cat::Cat(const Cat& instance)
{
	type = instance.type;
	brain = instance.brain;

	std::cout << "Cat Created.\n";
}

Cat& Cat::operator=(const Cat& instance)
{
	type = instance.type;
	brain = instance.brain;
	
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