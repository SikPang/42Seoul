/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:01:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/11/06 20:14:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define ANIMAL_NUM 6

// void leaks()
// {
// 	system("leaks brain");
// }

int main()
{
	//atexit(leaks);

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;
	delete i;

	Animal* animals[ANIMAL_NUM];

	std::cout << "\n--------------------------------------\n";
	for (int i=0; i<ANIMAL_NUM; ++i)
	{
		std::cout << i << " : ";
		if (i < ANIMAL_NUM/2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << "\n--------------------------------------\n";

	for (int i=0; i<ANIMAL_NUM; ++i)
		animals[i]->makeSound();
	std::cout << "\n--------------------------------------\n";

	Dog* dog = dynamic_cast<Dog*>(animals[0]);
	if (dog)
	{
		try
		{
			std::cout << "before idea : " << dog->GetIdea(0) << '\n';
			dog->AddIdea("I want to go home..", 0);
			std::cout << "after idea : " << dog->GetIdea(0) << '\n';

			dog->AddIdea("OutOfIdx", IDEA_CAPACITY + 1);
			std::cout << "access to max index + 1 : " << dog->GetIdea(IDEA_CAPACITY + 1) << "\n\n";
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	std::cout << "\n--------------------------------------\n";

	for (int i=0; i<ANIMAL_NUM; ++i)
	{
		std::cout << i << " : ";
	 	delete animals[i];
	}
	std::cout << "\n--------------------------------------\n";

	Cat* cat1 = new Cat();
	cat1->AddIdea("dup", 0);
	
	Cat* cat2 = new Cat();
	*cat2 = *cat1;
	delete cat1;
	try
	{
		std::cout << "cat2's idea[0] : " << cat2->GetIdea(0) << "\n\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete cat2;

	// Animal abstractTest;
	
	return 0;
}