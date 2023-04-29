/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:01:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 17:45:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define ANIMAL_NUM 6

void leaks()
{
	system("leaks brain");
}

int main()
{
	//atexit(leaks);

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;
	delete i;

	Animal* animals[ANIMAL_NUM];

	std::cout << "\n";
	for (int i=0; i<ANIMAL_NUM/2; ++i)
	{
		std::cout << i << ' ';
		animals[i] = new Dog();
		std::cout << "\n";
	}
	
	for (int i=ANIMAL_NUM/2; i<ANIMAL_NUM; ++i)
	{
		std::cout << i << ' ';
		animals[i] = new Cat();
		std::cout << "\n";
	}

	for (int i=0; i<ANIMAL_NUM; ++i)
		animals[i]->makeSound();
	std::cout << "\n";

	Dog* dog = dynamic_cast<Dog*>(animals[0]);

	std::cout << "before idea : " << dog->GetIdea(0) << '\n';
	dog->AddIdea("I want to go home..", 0);
	std::cout << "after idea : " << dog->GetIdea(0) << '\n';
	std::cout << "access to max index + 1 : " << dog->GetIdea(dog->GetSizeOfIdeas() + 1) << "\n\n";

	for (int i=0; i<ANIMAL_NUM; ++i)
	{
		std::cout << i << ' ';
	 	delete animals[i];
		std::cout << "\n";
	}

	Cat cat1;
	cat1.AddIdea("dup", 0);
	
	Cat cat2 = cat1;
	std::cout << "cat2's idea[0] : " << cat2.GetIdea(0) << "\n\n";

	Cat cat3;
	cat3 = cat1;
	std::cout << "cat3's idea[0] : " << cat3.GetIdea(0) << "\n\n";
	
	return 0;
}