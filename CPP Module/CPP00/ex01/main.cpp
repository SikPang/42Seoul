/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:55:09 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/13 22:39:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void Search()
{
	
}

void Add()
{
	
}

int main()
{
	while (true)
	{
		std::string input;
		
		std::string a = "asd";
		std::string b = "asdf";
		
		std::cout << "== You can use following commands [ADD, SEARCH, EXIT] ==\n";
		std::cin >> input;

		if (input == "ADD")
			Add();
		else if (input == "SEARCH")
			Search();
		else if (input == "EXIT")
			return 0;
		else
			std::cout << "wrong command\n\n";
	}
}