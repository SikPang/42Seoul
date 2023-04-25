/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:56:55 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 17:19:27 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	species = "FragTrap";

	std::cout << "FragTrap [Unknown] Created.\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	species = "FragTrap";

	std::cout << "FragTrap " << name << " Created.\n";
}

FragTrap::FragTrap(const FragTrap& instance) : ClapTrap(instance)
{
	std::cout << "FragTrap " << name << " Created.\n";
}

FragTrap& FragTrap::operator=(const FragTrap& instance)
{
	name = instance.name;
	hitPoint = instance.hitPoint;
	energyPoint = instance.energyPoint;
	attackDamage = instance.attackDamage;
	species = instance.species;

	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << CYN << ' ' << name << NC << " Destroyed.\n";
}

void FragTrap::highFivesGuys(void) const
{
	if (hitPoint == 0)
	{
		std::cout << species << " " << CYN << name << NC << " is dead but seems to wriggle.\n";	
		return;
	}
	
	std::string	input;

	while (true)
	{
		std::cout << "\t" << species << CYN << ' '  << name << NC << ": Can you give me a high five? (yes/no)\n";
		std::cin >> input;
		std::cin.ignore(100, '\n');
		if (std::cin.eof())
			exit(1);

		if (input == "yes")
		{
			std::cout << "\t" << "* Clap! * (" << CYN << name << NC << " looks happy)\n";
			return;
		}
		else if (input == "no")
		{
			std::cout << "\t" << ": (" << CYN << name << NC << " looks sad)\n";
			return;
		}
		else
			std::cout << "\t" << species << CYN << ' '  << name << NC << ": I don't understand.\n";
	}
}