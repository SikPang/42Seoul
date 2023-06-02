/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:26:40 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/02 22:50:26 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
	: stack()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN& other)
	: stack(other.stack)
{
}

RPN& RPN::operator=(const RPN& other)
{
	stack = other.stack;
	return *this;	
}

RPN& RPN::getInstance()
{
	static RPN instance;
	return instance;
}

void RPN::calculate(char* str)
{
	std::stack<int> newStack;
	stack.swap(newStack);

	std::stringstream ss(str);
	char num;

	while (true)
	{
		ss >> num;

		if (ss.eof())
			break;
			// 사칙연산도
		else if (ss.fail() || num < '0' || num > '9')
		{
			std::cout << "Error\n";
			return;
		}

		stack.push(num);
	}
}