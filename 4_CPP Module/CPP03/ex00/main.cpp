/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:01:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 17:12:06 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap	ctA("Alpha");
	ClapTrap	ctB("Beta");

	for (int i = 0; i < 10; ++i)
	{
		std::cout << '\n';
		ctA.attack("Beta");
		ctB.takeDamage(ctA.getAttackDamage());
	}

	std::cout << '\n';
	ctA.attack("Beta");
	ctA.beRepaired(1);
	
	std::cout << '\n';
	ctB.beRepaired(1);
	ctB.beRepaired(1);

	std::cout << '\n';
}