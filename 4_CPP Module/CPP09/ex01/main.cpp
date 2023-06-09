/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:09:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/09 14:08:46 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

// void v()
// {
// 	system("leaks RPN");
// }

int main(int ac, char** av)
{
	//atexit(v);
	if (ac != 2)
	{
		std::cout << "Error\n";
		return 1;
	}

	RPN& rpn = RPN::getInstance();

	try
	{
		rpn.calculate(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
		return 1;
	}
	return 0;
}