/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:55:09 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/18 14:40:36 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

static void cinException()
{
	std::cin.ignore(INT_MAX, '\n');
	if (std::cin.eof())
		exit(1);
}

static void GetInfo(PhoneBook& pb)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkestSecret;
	std::string phoneNumber;
	char		phoneNumberArr[PNUM_SIZE] = {};

	std::cout << CYN << "\n== put first name without space (1/5)\n" << NC;
	std::cin >> firstName;
	cinException();

	std::cout << CYN << "\n== put last name without space (2/5)\n" << NC;
	std::cin >> lastName;
	cinException();

	std::cout << CYN << "\n== put nick name without space (3/5)\n" << NC;
	std::cin >> nickName;
	cinException();

	std::cout << CYN << "\n== put phoneNumber without '-' and space (4/5)\n" << NC;
	std::cin >> phoneNumber;
	cinException();

	std::cout << CYN << "\n== put darkest secret without space (5/5)\n" << NC;
	std::cin >> darkestSecret;
	cinException();

	std::cout << "\n";

	for (int i=0; i<phoneNumber.size() && i<PNUM_SIZE-1; ++i)
		phoneNumberArr[i] = phoneNumber[i];

	pb.AddContact(firstName, lastName, nickName, darkestSecret, phoneNumberArr);
}

int main()
{
	PhoneBook pb;
	
	while (true)
	{
		std::string input;
		
		std::cout << GRN << "== You can use following commands [ADD, SEARCH, EXIT] ==\n" << NC;
		std::cin >> input;
		cinException();
		
		if (input == "ADD")
			GetInfo(pb);
		else if (input == "SEARCH")
			pb.PrintPhoneBook();
		else if (input == "EXIT")
			return 0;
		else
			std::cout << RED << "wrong command\n\n" << NC;
	}
}