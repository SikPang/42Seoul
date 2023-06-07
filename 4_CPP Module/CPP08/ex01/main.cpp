/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:56:54 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/07 12:18:10 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Span.hpp"

void myTest(int size)
{
	std::cout << "----- test start (size :" << size << ") -----\n";
	Span span(size);

	try
	{
		span.fillNumbers();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	span.sort();
	span.print();

	try
	{
		std::cout << "longest span : " << span.longestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		std::cout << "shortest span : " << span.shortestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	std::cout << "\n";
}

int main()
{
	Span sp = Span(10);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;

	sp.fillNumbers();
	sp.sort();
	sp.print();
	std::cout << "longest span : " << sp.longestSpan() << "\n";
	std::cout << "shortest span : " << sp.shortestSpan() << "\n\n";

	std::cout << "----- test start (insert) -----\n";
	std::vector<int> temp;
	temp.push_back(4);
	temp.push_back(-2);
	temp.push_back(8);
	temp.push_back(-10);
	temp.push_back(32);

	Span insertTest(temp.size() + 2);
	insertTest.addNumber(42);
	insertTest.addNumber(42);
	for (int i = 0; i < 2; ++i)
	{
		try
		{
			insertTest.insert(temp.begin(), temp.end());
			insertTest.print();
			std::cout << "longest span : " << insertTest.longestSpan() << "\n";
			std::cout << "shortest span : " << insertTest.shortestSpan() << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	std::cout << "\n";

	std::cout << "----- test start (copy operator) -----\n";
	sp = insertTest;
	sp.print();
	std::cout << "longest span : " << sp.longestSpan() << "\n";
	std::cout << "shortest span : " << sp.shortestSpan() << "\n\n";	
	
	myTest(-1);
	myTest(0);
	myTest(1);
	myTest(2);
	myTest(10);
	myTest(20);
	//myTest(10000);

	std::cout << sp[1] << "\n";
	sp[1] = 0;
	std::cout << sp[1] << "\n";

	return 0;
}