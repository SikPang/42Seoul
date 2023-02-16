/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:05:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 16:51:31 by kwsong           ###   ########.fr       */
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
	species = "ClapTrap";

	std::cout << "ClapTrap [Unknown] Created.\n";
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
	species = "ClapTrap";

	std::cout << "ClapTrap " << name << " Created.\n";
}

ClapTrap::ClapTrap(ClapTrap& instance)
{
	name = instance.name;
	hitPoint = instance.hitPoint;
	energyPoint = instance.energyPoint;
	attackDamage = instance.attackDamage;
	species = instance.species;

	std::cout << "ClapTrap " << name << " Created.\n";
}

ClapTrap& ClapTrap::operator=(ClapTrap& instance)
{
	name = instance.name;
	hitPoint = instance.hitPoint;
	energyPoint = instance.energyPoint;
	attackDamage = instance.attackDamage;
	species = instance.species;
	
	return *this;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap " << name << " Destroyed.\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoint == 0)
		std::cout << species << " " << name << " failed to attack " << target << " (low Energy point)\n";
	else
	{
		--energyPoint;
		std::cout << species << " "  << name << " attacks " << target << ", causing " << attackDamage
			<< " point(s) of damage! (" << energyPoint << " Energy point(s) left)\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoint == 0)
		std::cout << species << " "  << name << " already died. \n";
	else if ((int)(hitPoint - amount) <= 0)
	{
		hitPoint = 0;
		std::cout << species << " "  << name << " taked " << amount
			<< " point(s) of damage! (died)\n";
	}
	else
	{
		hitPoint -= amount;
		std::cout << species << " "  << name << " taked " << amount
			<< " point(s) of damage! (" << hitPoint << " Hit point(s) left)\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoint == 0)
		std::cout << species << " "  << name << " failed to repair (low energyPoint)\n";
	else
	{
		hitPoint += amount;
		if (hitPoint == 1)
			std::cout << species << " "  << name << " revive itself (" << hitPoint << " Hit point(s) left)\n";
		else
			std::cout << species << " "  << name << " repaired itself " << amount
				<< " points! (" << hitPoint << " Hit point(s) left)\n";
	}
}

int ClapTrap::getAttackDamage()
{
	return attackDamage;
}