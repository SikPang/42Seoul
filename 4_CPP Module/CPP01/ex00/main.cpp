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

#include "Zombie.hpp"

int main()
{
	Zombie*	heapZombie = new Zombie("heap");
	Zombie	stackZombie("stack");

	Zombie* newZom = newZombie("newZombie");
	randomChump("randomChump");

	delete newZom;
	delete heapZombie;
}