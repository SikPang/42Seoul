/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:44:38 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/15 17:29:49 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "Failed to create horde named \"" << name << "\"\n";
		return 0;
	}
	
	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; ++i)
		horde[i].setName(name);
	return horde;
}