/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:05:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 14:02:22 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = "";
	species = "ClapTrap";
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;

	std::cout << species << CYN << " [Unknown]" << NC << " Created.\n";
}

ClapTrap::ClapTrap(const std::string& name)
{
	this->name = name;
	species = "ClapTrap";
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;

	std::cout << species << CYN << ' ' << this->name << NC << " Created.\n";
}

ClapTrap::ClapTrap(const ClapTrap& instance)
{
	name = instance.name;
	hitPoint = instance.hitPoint;
	energyPoint = instance.energyPoint;
	attackDamage = instance.attackDamage;

	std::cout << species << CYN << ' ' << name << NC << " Created.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& instance)
{
	name = instance.name;
	hitPoint = instance.hitPoint;
	energyPoint = instance.energyPoint;
	attackDamage = instance.attackDamage;
	
	return *this;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap" << CYN << ' ' << name << NC << " Destroyed.\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoint == 0)
		std::cout << species << CYN << ' ' << name << NC << " failed to attack " << target << " (low Energy point)\n";
	else
	{
		--energyPoint;
		std::cout << species << CYN << ' ' << name << RED << " attacks " << NC << target << ", causing " << attackDamage
			<< " point(s) of damage! (" << energyPoint << " Energy point(s) left)\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoint == 0)
		std::cout << species << CYN << ' ' << name << NC << " already died. \n";
	else if (amount >= hitPoint)
	{
		hitPoint = 0;
		std::cout << species << CYN << ' ' << name << NC << " taked " << amount
			<< " point(s) of damage! " << RED << "(died)\n" << NC;
	}
	else
	{
		hitPoint -= amount;
		std::cout << species << CYN << ' ' << name << NC << " taked " << amount
			<< " point(s) of damage! (" << hitPoint << " Hit point(s) left)\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoint == 0)
		std::cout << species << CYN << ' ' << name << NC << " failed to repair (low energyPoint)\n";
	else
	{
		hitPoint += amount;
		if (hitPoint == amount)
			std::cout << species << CYN << ' ' << name << GRN << " revive" << NC << " itself ("
				 << hitPoint << " Hit point(s) left)\n";
		else
			std::cout << species << CYN << ' ' << name << GRN << " repaired " << NC << "itself " << amount
				<< " points! (" << hitPoint << " Hit point(s) left)\n";
	}
}

unsigned int ClapTrap::getAttackDamage() const
{
	return attackDamage;
}