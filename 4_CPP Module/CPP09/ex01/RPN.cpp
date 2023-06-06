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
	std::stack<long> newStack;
	swap(stack, newStack);

	std::stringstream ss(str);
	char num;

	while (ss >> num)
	{
		if ((num < '0' || num > '9') 
			&& (num != '+' && num != '-' && num != '*' && num != '/'))
			throw RPN::Error();

		if (num >= '0' && num <= '9')
			stack.push(num - '0'); 
		else if (num == '+' || num == '-' || num == '*' || num == '/')
		{
			if (stack.size() < 2)
				throw RPN::Error();
			long second = stack.top();
			stack.pop();

			long first = stack.top();
			stack.pop();

			switch(num)
			{
			case '+':
				stack.push(first + second);
				break;
			case '-':
				stack.push(first - second);
				break;
			case '*':
				stack.push(first * second);
				break;
			case '/':
				if (second == 0)
					throw RPN::Error();
				stack.push(first / second);
				break;
			}
		}
	}

	if (stack.size() != 1)
		throw RPN::Error();
	std::cout << stack.top() << "\n";
}


// ----- Exception -----

const char* RPN::Error::what() const throw()
{
	return "Error\n";
}