/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:01:22 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/26 19:09:46 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void PrevFunc()
{
	ClapTrap	ctA("A");
	ClapTrap	ctB("B");

	for (int i = 0; i < 10; ++i)
	{
		std::cout << '\n';
		ctA.attack("B");
		ctB.takeDamage(ctA.getAttackDamage());
	}

	std::cout << '\n';
	ctA.attack("B");
	ctA.beRepaired(1);
	
	std::cout << '\n';
	ctB.beRepaired(1);
	ctB.beRepaired(1);

	std::cout << '\n';
}

void CheckBIsAlive(ScavTrap& stB)
{
	std::cout << "is ScavTrap" << CYN << " B " << NC << "Alive? : " << stB.IsAlive() << "\n\n";
}

void PrevFunc2()
{
	ScavTrap	stA("A");
	ScavTrap	stB("B");

	std::cout << '\n';
	for (int i = 0; i < 6; ++i)
	{
		stA.attack("B");
		stB.takeDamage(stA.getAttackDamage());
		CheckBIsAlive(stB);
	}

	stB.beRepaired(20);
	stB.guardGate();
	stB.attack("A");

	std::cout << '\n';
	stA.beRepaired(20);

	std::cout << '\n';
	stA.guardGate();
	stA.guardGate();
	
	std::cout << '\n';
}

int main()
{
	PrevFunc();
	std::cout << "\n-----------------------------------\n\n";
	PrevFunc2();
	std::cout << "\n-----------------------------------\n\n";

	FragTrap ftA("A");
	FragTrap ftB("B");

	for (int i = 0; i < 3; ++i)
	{
		std::cout << '\n';
		ftA.attack("B");
		ftB.takeDamage(ftA.getAttackDamage());
	}
	ftB.beRepaired(1);
	ftB.highFivesGuys();

	std::cout << '\n';
	ftA.attack("B");
	ftB.takeDamage(ftA.getAttackDamage());
	
	std::cout << '\n';
	ftB.beRepaired(1);
	ftB.highFivesGuys();
	ftB.attack("A");

	std::cout << '\n';
}