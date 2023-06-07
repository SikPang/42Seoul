/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:56:54 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/07 12:03:33 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include "easyfind.hpp"

template <typename T>
void find_test(T& arr, int target)
{
	typename T::iterator iter = easyfind(arr, target);

	std::cout << "target : " << target;
	
	if (iter != arr.end())
		std::cout << ", Found\n";
	else
		std::cout << ", Not found\n";
}

int main()
{
	std::cout << "\n----- list test -----\n";
	std::list<int> list;
	list.push_back(1);
	list.push_back(2);
	find_test(list, 2);
	find_test(list, 3);

	std::cout << "\n----- vector test -----\n";
	std::vector<float> vec;
	vec.push_back(2.1f);
	vec.push_back(3.f);
	find_test(vec, 2);
	find_test(vec, 3);

	std::cout << "\n----- deque test -----\n";
	std::deque<char> deq;
	deq.push_back('a');
	deq.push_back(' ');
	find_test(deq, 'a');
	find_test(deq, 10);

	std::cout << "\n----- string test -----\n";
	std::string str = "hello";
	find_test(str, 'h');
	find_test(str, 'z');

	std::cout << "\n----- set test -----\n";
	std::set<int> set;
	set.insert(1);
	set.insert(2);
	find_test(set, 1);
	find_test(set, 2);
	find_test(set, 3);
}