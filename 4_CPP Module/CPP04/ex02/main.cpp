/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:01:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 19:47:35 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define ANIMAL_NUM 10

int main()
{
	const Animal* animals[ANIMAL_NUM];

	for (int i=0; i<ANIMAL_NUM/2; ++i)
	{
		animals[i] = new Cat();
		std::cout << "\n";
	}
	
	for (int i=ANIMAL_NUM/2; i<ANIMAL_NUM; ++i)
	{
		animals[i] = new Cat();
		std::cout << "\n";
	}

	for (int i=0; i<ANIMAL_NUM; ++i)
	{
		std::cout << "\n";
	 	delete animals[i];
	}

	// 안 되는 것 확인용
	// Animal a;
	// Animal* pa = new Animal();

	return 0;
}