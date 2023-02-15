/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:32:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/15 17:46:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	pStr = &str;
	std::string&	rStr = str;

	std::cout << "address of str  : " << &str << '\n';
	std::cout << "address of pStr : " << pStr << '\n';
	std::cout << "address of rStr : " << &rStr << "\n\n";

	std::cout << "value of str  : " << str << '\n';
	std::cout << "value of pStr : " << *pStr << '\n';
	std::cout << "value of rStr : " << rStr << '\n';
}