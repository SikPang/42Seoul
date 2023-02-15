/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:05:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/15 21:44:33 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = "";
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	name = name;
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap& instance)
{
	name = instance.name;
	hitPoint = instance.hitPoint;
	energyPoint = instance.energyPoint;
	attackDamage = instance.attackDamage;
}

ClapTrap& ClapTrap::operator=(ClapTrap& instance)
{
	name = instance.name;
	hitPoint = instance.hitPoint;
	energyPoint = instance.energyPoint;
	attackDamage = instance.attackDamage;
	
	return *this;
}

ClapTrap::~ClapTrap() {}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoint == 0)
		std::cout << "ClapTrap " << name << " failed to attack " << target << " (low energyPoint)\n";
	else
	{
		--energyPoint;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage
			<< " points of damage! (" << energyPoint << " point(s) left)\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoint == 0)
		std::cout << "ClapTrap " << name << " already died. \n";
	else if (hitPoint - amount <= 0)
	{
		hitPoint = 0;
		std::cout << "ClapTrap " << name << " taked " << amount
			<< " points of damage! (died)\n";
	}
	else
	{
		hitPoint -= amount;
		std::cout << "ClapTrap " << name << " taked " << amount
			<< " points of damage! (" << hitPoint << " point(s) left)\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoint == 0)
		std::cout << "ClapTrap " << name << " failed to repair (low energyPoint)\n";
	else
	{
		hitPoint += amount;
		if (hitPoint == 0)
		{
			hitPoint += amount;
			std::cout << "ClapTrap " << name << " revive itself (" << hitPoint << " point(s) left)\n";
		}
		else
		{
			hitPoint += amount;
			std::cout << "ClapTrap " << name << " repaired itself " << amount
				<< " points! (" << hitPoint << " point(s) left)\n";
		}
	}
}

int ClapTrap::getAttackDamage()
{
	return attackDamage;
}