/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:12:50 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/15 16:12:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
	name = "";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie(Zombie& instance)
{
	name = instance.name;
}

Zombie& Zombie::operator=(Zombie& instance)
{
	name = instance.name;
	return *this;
}

Zombie::~Zombie()
{
	die();
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::die()
{
	std::cout << name << " died\n";
}

void Zombie::setName(std::string name)
{
	this->name = name;
}