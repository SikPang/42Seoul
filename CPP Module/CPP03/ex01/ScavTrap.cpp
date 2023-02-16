/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:10:09 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 16:49:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	isAlive = true;
	isGateKeeperMode = false;
	species = "ScavTrap";

	std::cout << "ScavTrap [Unknown] Created.\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	isAlive = true;
	isGateKeeperMode = false;
	species = "ScavTrap";

	std::cout << "ScavTrap " << name << " Created.\n";
}

ScavTrap::ScavTrap(ScavTrap& instance) : ClapTrap(instance)
{
	isAlive = instance.isAlive;
	isGateKeeperMode = instance.isGateKeeperMode;
	
	std::cout << "ScavTrap " << name << " Created.\n";
}

ScavTrap& ScavTrap::operator=(ScavTrap& instance)
{
	name = instance.name;
	hitPoint = instance.hitPoint;
	energyPoint = instance.energyPoint;
	attackDamage = instance.attackDamage;
	isAlive = instance.isAlive;
	isGateKeeperMode = instance.isGateKeeperMode;
	species = instance.species;

	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " Destroyed.\n";
}

void ScavTrap::takeDamage(unsigned int amount)
{
	ClapTrap::takeDamage(amount);

	if (hitPoint == 0 && isAlive)
		isAlive = false;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	ClapTrap::beRepaired(amount);

	if (hitPoint > 0 && !isAlive)
		isAlive = true;
}

void ScavTrap::guardGate()
{
	if (isGateKeeperMode)
		std::cout << "Gate keeper mode of " << name << " is ON\n";
	else
		std::cout << "Gate keeper mode of " << name << " is OFF\n";
}

bool ScavTrap::IsAlive()
{
	return isAlive;
}