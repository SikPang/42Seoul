/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:32:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 14:25:56 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"

int main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	pStr = &str;
	std::string&	rStr = str;

	std::cout << "address of " << RED << "str  : " << NC << &str << '\n';
	std::cout << "address of " << GRN << "pStr : " << NC << pStr << '\n';
	std::cout << "address of " << CYN << "rStr : " << NC << &rStr << "\n\n";

	std::cout << "value of " << RED << "str  : " << NC << str<< '\n';
	std::cout << "value of " << GRN << "pStr : " << NC << *pStr<< '\n';
	std::cout << "value of " << CYN << "rStr : " << NC << rStr << '\n';
}