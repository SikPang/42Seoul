/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:26:42 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/02 22:46:42 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <sstream>
#include <exception>

class RPN
{
private:
	std::stack<long> stack;

private:
	RPN();
	RPN(const RPN& other);
	~RPN();
	RPN& operator=(const RPN& other);

public:
	static RPN& getInstance();
	void calculate(char* str);

public:
	class Error : public std::exception
	{
	public:
		const char* what() const throw();
	};
};