/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:49:30 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/25 21:40:38 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <exception>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	srand(time(NULL));
	
	int randNum = rand() % 3;
	
	switch(randNum)
	{
	case 0:
		std::cout << "--- A generated\n";
		return new A;
	case 1:
		std::cout << "--- B generated\n";
		return new B;
	default:
		std::cout << "--- C generated\n";
		return new C;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "identify * result : A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "identify * result : B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "identify * result : C\n";
	else
		std::cout << "identify * result : Base\n";
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
	}
	catch (std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
		}
		catch (std::exception& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
			}
			catch (std::exception& e)
			{
				std::cout << "identify & result : Base\n";
				return;
			}
			std::cout << "identify & result : C\n";
			return;
		}
		std::cout << "identify & result : B\n";
		return;
	}
	std::cout << "identify & result : A\n";
}

int main()
{
	Base* child = generate();
	identify(child);
	identify(*child);

	Base* base = new Base;
	identify(base);
	identify(*base);

	delete base;
	delete child;
}