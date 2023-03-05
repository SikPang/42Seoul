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
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	species = "FragTrap";

	std::cout << "FragTrap [Unknown] Created.\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	species = "FragTrap";

	std::cout << "FragTrap " << name << " Created.\n";
}

FragTrap::FragTrap(FragTrap& instance) : ClapTrap(instance)
{
	std::cout << "FragTrap " << name << " Created.\n";
}

FragTrap& FragTrap::operator=(FragTrap& instance)
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
	std::cout << "FragTrap " << name << " Destroyed.\n";
}

void FragTrap::highFivesGuys()
{
	if (hitPoint == 0)
	{
		std::cout << species << " " << name << " is dead but seems to wriggle.\n";	
		return;
	}
	
	std::string	input;

	while (true)
	{
		std::cout << "\t" << species << " " << name << ": Can you give me a high five? (yes/no)\n";
		std::cin >> input;

		if (input == "yes")
		{
			std::cout << "\t" << species << " " << name << ": * Clap! * (looks happy)\n";
			return;
		}
		else if (input == "no")
		{
			std::cout << "\t" << species << " " << name << ": (looks sad)\n";
			return;
		}
		else
			std::cout << "\t" << species << " " << name << ": I don't understand.\n";
	}
}