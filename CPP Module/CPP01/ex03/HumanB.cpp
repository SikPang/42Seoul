/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:12:42 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/15 18:39:57 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB()
{
	name = "";
	weapon = NULL;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::HumanB(HumanB& instance)
{
	name = instance.name;
	weapon = instance.weapon;
}

HumanB& HumanB::operator=(HumanB& instance)
{
	name = instance.name;
	weapon = instance.weapon;
	return *this;
}

HumanB::~HumanB() {}

void HumanB::attack()
{
	std::cout << name << " attacks with their ";
	
	if (weapon == NULL)
		std::cout << "fist\n";
	else
		std::cout << weapon->getType() << "\n";
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}