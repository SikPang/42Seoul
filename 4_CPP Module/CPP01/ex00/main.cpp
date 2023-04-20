/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:38:57 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 13:53:35 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie*	heapZom = new Zombie("Heap");
	Zombie	stackZom("Stack");

	Zombie* newZom = newZombie("NewZombie()");
	randomChump("RandomChump()");

	delete newZom;
	delete heapZom;
}