/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:56:54 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/29 22:24:16 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Span.hpp"

void test(int size)
{
	std::cout << "--- test start (size :" << size << ")\n";
	Span span(size);

	try
	{
		span.fillNumbers();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	span.sortAndPrint();

	try
	{
		std::cout << "longest span : " << span.longestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "shortest span : " << span.shortestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
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
	sp.sortAndPrint();
	std::cout << "longest span : " << sp.longestSpan() << "\n";
	std::cout << "shortest span : " << sp.shortestSpan() << "\n\n";

	std::cout << "--- test start (insert)\n";
	std::vector<int> temp;
	temp.push_back(4);
	temp.push_back(-2);
	temp.push_back(8);
	temp.push_back(-10);
	temp.push_back(32);

	Span insertTest(temp.size());
	for (int i = 0; i < 2; ++i)
	{
		try
		{
			insertTest.insert(temp.begin(), temp.end());
			insertTest.sortAndPrint();
			std::cout << "longest span : " << insertTest.longestSpan() << "\n";
			std::cout << "shortest span : " << insertTest.shortestSpan() << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "\n";

	std::cout << "--- test start (copy operator)\n";
	sp = insertTest;
	sp.sortAndPrint();
	std::cout << "longest span : " << sp.longestSpan() << "\n";
	std::cout << "shortest span : " << sp.shortestSpan() << "\n\n";	
	
	test(-1);
	test(0);
	test(1);
	test(2);
	test(10);
	test(20);
	//test(10000);

	return 0;
}