/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:56:54 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/05 21:52:58 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <string>
#include "MutantStack.hpp"

template <typename T>
void test(T& m, const std::string& name)
{
	std::cout << "-------------------- TEST for " << name << " --------------------\n\n";
	T cm(m);
	T rm(m);
	T crm(m);

	std::cout << "----- iterator for " << name << "\n";
	typename T::iterator iter = m.begin();
	
	for (; iter != m.end(); ++iter)
	{
		std::cout << *iter << " ";
		*iter = 10;
	}
	std::cout << "\n";
	
	for (iter = m.begin(); iter != m.end(); ++iter)
		std::cout << *iter << " ";

	std::cout << "\n\n----- const_iterator for " << name << "\n";
	typename T::const_iterator citer = cm.begin();

	for (; citer != cm.end(); ++citer)
	{
		std::cout << *citer << " ";
		//*citer = 10;
	}

	std::cout << "\n\n----- reverse_iterator for " << name << "\n";
	typename T::reverse_iterator riter = rm.rbegin();
	
	for (; riter != rm.rend(); ++riter)
	{
		std::cout << *riter << " ";
		*riter = 10;
	}
	std::cout << "\n";
	
	for (riter = rm.rbegin(); riter != rm.rend(); ++riter)
		std::cout << *riter << " ";

	std::cout << "\n\n----- const_reverse_iterator for " << name << "\n";
	typename T::const_reverse_iterator criter = crm.rbegin();
	
	for (; criter != crm.rend(); ++criter)
	{
		std::cout << *criter << " ";
		//*criter = 10;
	}
	std::cout << "\n\n";
}

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	MutantStack<int> m;
	m.push(1);
	m.push(2);
	m.push(3);
	m.push(4);
	m.push(5);
	
	std::list<int> list(m.begin(), m.end());
	std::deque<int> deq(m.begin(), m.end());
	std::vector<int> vec(m.begin(), m.end());

	test(m, "MutantStack");
	test(list, "std::list");
	test(deq, "std::deque");
	test(vec, "std::vector");
}