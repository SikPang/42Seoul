/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:55:09 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/17 20:00:11 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

void GetInfo(PhoneBook& pb)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkestSecret;
	std::string phoneNumber;
	char		phoneNumberArr[PNUM_SIZE];

	std::cout << CYN << "\n== put first name without space (1/5)\n" << NC;
	std::cin >> firstName;
	std::cin.ignore(INT_MAX, '\n');

	std::cout << CYN << "\n== put last name without space (2/5)\n" << NC;
	std::cin >> lastName;
	std::cin.ignore(INT_MAX, '\n');

	std::cout << CYN << "\n== put nick name without space (3/5)\n" << NC;
	std::cin >> nickName;
	std::cin.ignore(INT_MAX, '\n');

	std::cout << CYN << "\n== put phoneNumber without '-' and space (4/5)\n" << NC;
	std::cin >> phoneNumber;
	std::cin.ignore(INT_MAX, '\n');

	std::cout << CYN << "\n== put darkest secret without space (5/5)\n" << NC;
	std::cin >> darkestSecret;
	std::cin.ignore(INT_MAX, '\n');

	std::cout << "\n";

	for (int i=0; i<phoneNumber.size() && i<20; ++i)
		phoneNumberArr[i] = phoneNumber[i];

	for (int i=phoneNumber.size(); i<PNUM_SIZE; ++i)
		phoneNumberArr[i] = '\0';

	pb.AddContact(firstName, lastName, nickName, darkestSecret, &phoneNumberArr[0]);
}

int main()
{
	PhoneBook pb;
	
	while (true)
	{
		std::string input;
		
		std::cout << GRN << "== You can use following commands [ADD, SEARCH, EXIT] ==\n" << NC;
		std::cin >> input;
		std::cin.ignore(INT_MAX, '\n');
		
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