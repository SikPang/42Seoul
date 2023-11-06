/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:46:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/11/06 22:27:38 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

// void leaks()
// {
// 	system("leaks interface");
// }

void MyTest()
{
	MateriaSource ms;
	ms.createMateria("something");
	ms.createMateria("ice");
	ms.createMateria("cure");

	ms.learnMateria(new Ice());
	AMateria* newMateria1 = ms.createMateria("ice");

	Character player("kwsong");
	std::cout << player.getName() << " Created.\n";

	try
	{
		player.unequip(0);
	}
	catch(const std::exception& e)
	{
		std::cout << "! unequip 0 : "<< e.what() << "\n";
	}

	try
	{
		player.unequip(-1);
	}
	catch(const std::exception& e)
	{
		std::cout << "! unequip -1 : "<< e.what() << "\n";
	}

	try
	{
		player.unequip(100);
	}
	catch(const std::exception& e)
	{
		std::cout <<"! unequip 100 : "<<  e.what() << "\n";
	}
	
	player.equip(NULL);
	player.equip(newMateria1);

	Character enemy("bear");
	std::cout << enemy.getName() << " Created.\n";

	try
	{
		player.use(-1, enemy);
	}
	catch(const std::exception& e)
	{
		std::cout <<"! use -1 : "<<  e.what() << "\n";
	}

	try
	{
		player.use(100, enemy);
	}
	catch(const std::exception& e)
	{
		std::cout <<"! use 100 : "<<  e.what() << "\n";
	}

	try
	{
		player.use(1, enemy);
	}
	catch(const std::exception& e)
	{
		std::cout <<"! use 1 : "<<  e.what() << "\n";
	}

	try
	{
		player.use(0, enemy);
	}
	catch(const std::exception& e)
	{
		std::cout <<"! use 0 : "<<  e.what() << "\n";
	}

	player.equip(ms.createMateria("cure"));
	player.use(1, enemy);
	
	ms.learnMateria(new Cure());
	AMateria* newMateria2 = ms.createMateria("cure");
	player.equip(newMateria2);
	player.use(1, enemy);

	AMateria* newMateria3 = ms.createMateria("cure");
	AMateria* newMateria4 = ms.createMateria("cure");
	AMateria* newMateria5 = ms.createMateria("cure");
	player.equip(newMateria3);
	player.equip(newMateria4);
	player.equip(newMateria5);
	
	try
	{
		player.unequip(2);
	}
	catch(const std::exception& e)
	{
		std::cout <<"! unequip 2 : "<<  e.what() << "\n";
	}
	player.use(2, enemy);

	player.equip(newMateria3);

	try
	{
		player.unequip(0);
		player.unequip(1);
		player.unequip(2);
		player.unequip(3);
	}
	catch(const std::exception& e)
	{
		std::cout <<"! unequip All : "<<  e.what() << "\n";
	}
	player.use(0, enemy);

	delete newMateria1;
	delete newMateria2;
	delete newMateria3;
	delete newMateria4;
	delete newMateria5;
}

int main()
{
	// atexit(leaks);
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

	// MyTest();
	return 0;
}