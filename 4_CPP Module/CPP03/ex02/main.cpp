/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:01:22 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 17:21:24 by kwsong           ###   ########.fr       */
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

int main()
{
	PrevFunc();
	std::cout << "\n-----------------------------------\n\n";

	FragTrap ftA("A");
	FragTrap ftB("B");

	for (int i = 0; i < 5; ++i)
	{
		std::cout << '\n';
		ftA.attack("B");
		ftB.takeDamage(ftA.getAttackDamage());
	}
	ftB.highFivesGuys();
	
	std::cout << '\n';
	ftB.beRepaired(1);
	ftB.highFivesGuys();

	std::cout << '\n';
}