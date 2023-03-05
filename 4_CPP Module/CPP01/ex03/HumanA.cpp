/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:12:42 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/15 18:38:44 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA()
{
	name = "";
	weapon = NULL;
}

HumanA::HumanA(std::string name, Weapon& weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

HumanA::HumanA(HumanA& instance)
{
	name = instance.name;
	weapon = instance.weapon;
}

HumanA& HumanA::operator=(HumanA& instance)
{
	name = instance.name;
	weapon = instance.weapon;
	return *this;
}

HumanA::~HumanA() {}

void HumanA::attack()
{
	if (weapon == NULL)
		std::cout << "Error : HumanA has no weapon\n";
	else
		std::cout << name << " attacks with their " << weapon->getType() << "\n";
}