/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:12:50 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 13:57:15 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << name << GRN << " created\n" << NC;
	name = "";
}

Zombie::Zombie(std::string name)
{
	std::cout << name << GRN << " created\n" << NC;
	this->name = name;
}

Zombie::Zombie(Zombie& instance)
{
	std::cout << name << GRN << " created\n" << NC;
	name = instance.name;
}

Zombie& Zombie::operator=(Zombie& instance)
{
	std::cout << name << GRN << " created\n" << NC;
	name = instance.name;
	return *this;
}

Zombie::~Zombie()
{
	std::cout << name << RED << " died\n" << NC;
}

void Zombie::announce()
{
	std::cout << name << CYN << ": BraiiiiiiinnnzzzZ...\n" << NC;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}