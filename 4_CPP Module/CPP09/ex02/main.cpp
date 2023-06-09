/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:09:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/09 13:26:04 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

// void v()
// {
// 	system("leaks PmergeMe");
// }

int main(int ac, char** av)
{
	//atexit(v);
	if (ac < 2)
	{
		std::cout << "Error\n";
		return 1;
	}
	
	PmergeMe& p = PmergeMe::getInstance();

	try
	{
		p.sort(av);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
		return 1;
	}
	
	return 0;
}