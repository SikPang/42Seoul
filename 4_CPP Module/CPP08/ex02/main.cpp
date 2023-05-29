/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:56:54 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/29 20:54:27 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include <stack>
#include <queue>
#include "easyfind.hpp"

template <typename T>
void test(T& arr, int target)
{
	typename T::iterator iter = easyfind(arr, target);
	
	if (iter != arr.end())
		std::cout << *iter << "\n";
	else
		std::cout << "not Found\n";
}

int main()
{
	std::list<int> list;
	list.push_back(1);
	list.push_back(2);
	test(list, 2);
	test(list, 3);

	std::vector<float> vec;
	vec.push_back(2.1f);
	vec.push_back(3.f);
	test(vec, 2);
	test(vec, 3);

	std::deque<char> deq;
	deq.push_back('a');
	deq.push_back(' ');
	test(deq, 'a');
	test(deq, 10);

	std::string str = "hello";
	test(str, 'h');
	test(str, 'z');
}