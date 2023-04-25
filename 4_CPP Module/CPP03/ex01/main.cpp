/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:01:22 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 17:21:38 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

void CheckBIsAlive(ScavTrap& stB)
{
	std::cout << "is ScavTrap" << CYN << " B " << NC << "Alive? : " << stB.IsAlive() << "\n\n";
}

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

int main()
{
	PrevFunc();
	std::cout << "\n-----------------------------------\n\n";

	ScavTrap	stA("A");
	ScavTrap	stB("B");

	for (int i = 0; i < 6; ++i)
	{
		std::cout << '\n';
		stA.attack("B");
		stB.takeDamage(stA.getAttackDamage());
		CheckBIsAlive(stB);
	}

	std::cout << '\n';
	stB.beRepaired(20);
	CheckBIsAlive(stB);

	std::cout << '\n';
	stB.beRepaired(20);
	CheckBIsAlive(stB);

	stB.guardGate();
	stB.guardGate();
	
	std::cout << '\n';
}