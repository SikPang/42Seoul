/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:38:57 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/14 22:39:23 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
	Zombie* horde1 = zombieHorde(HordeNum::FIRST, "horde1");
	Zombie* horde2 = zombieHorde(HordeNum::SECOND, "horde2");
	Zombie* horde3 = zombieHorde(HordeNum::THIRD, "horde3");

	for (int i = 0; i < HordeNum::FIRST; ++i)
		horde1[i].announce();
	std::cout << '\n';

	for (int i = 0; i < HordeNum::SECOND; ++i)
		horde2[i].announce();
	std::cout << '\n';

	for (int i = 0; i < HordeNum::THIRD; ++i)
		horde3[i].announce();
	std::cout << '\n';

	delete[] horde1;
	std::cout << '\n';

	delete[] horde2;
	std::cout << '\n';

	delete[] horde3;
}