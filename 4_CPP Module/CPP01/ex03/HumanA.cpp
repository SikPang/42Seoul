/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:12:42 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 14:21:57 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

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
	std::cout << name << RED << " attacks " << NC << "with their " 
		<< RED << weapon->getType() << NC << "\n";
}