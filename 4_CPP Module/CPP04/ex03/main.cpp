/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:46:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/12 21:09:57 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void leaks()
{
	system("leaks interface");
}

void MyTest()
{
	MateriaSource ms;
	std::cout << ms.createMateria("else") << '\n';
	std::cout << ms.createMateria("ice") << '\n';
	std::cout << ms.createMateria("cure") << '\n';

	ms.learnMateria(new Ice());
	AMateria* newMateria1 = ms.createMateria("ice");
	std::cout << newMateria1 << '\n';

	Character player("kwsong");
	std::cout << player.getName() << " Created.\n";
	player.unequip(-1);
	player.unequip(100);
	player.unequip(0);
	std::cout << "size of inventory : " << player.GetSizeOfInventory() << '\n';
	
	player.equip(NULL);
	player.equip(newMateria1);
	std::cout << "size of inventory : " << player.GetSizeOfInventory() << '\n';

	Character enemy("bear");
	std::cout << enemy.getName() << " Created.\n";
	player.use(-1, enemy);
	player.use(100, enemy);
	player.use(1, enemy);
	player.use(0, enemy);

	player.equip(ms.createMateria("cure"));
	std::cout << "size of inventory : " << player.GetSizeOfInventory() << '\n';

	ms.learnMateria(new Cure());
	AMateria* newMateria2 = ms.createMateria("cure");
	player.equip(newMateria2);
	std::cout << "size of inventory : " << player.GetSizeOfInventory() << '\n';
	player.use(1, enemy);

	player.unequip(2);
	std::cout << "size of inventory : " << player.GetSizeOfInventory() << '\n';
	player.unequip(1);
	std::cout << "size of inventory : " << player.GetSizeOfInventory() << '\n';
	player.unequip(0);
	std::cout << "size of inventory : " << player.GetSizeOfInventory() << '\n';

	delete newMateria1;
	delete newMateria2;
}

int main()
{
	atexit(leaks);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;

	//MyTest();
	return 0;
}