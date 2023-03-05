/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:55:09 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/14 21:24:42 by kwsong           ###   ########.fr       */
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

	std::cout << "\n== put first name (1/5)\n";
	std::cin >> firstName;

	std::cout << "\n== put last name (2/5)\n";
	std::cin >> lastName;

	std::cout << "\n== put nick name (3/5)\n";
	std::cin >> nickName;

	std::cout << "\n== put darkest secret (4/5)\n";
	std::cin >> darkestSecret;

	std::cout << "\n== put phoneNumber without '-' (maximum 20 characters) (5/5)\n\n";
	std::cin >> phoneNumber;

	for (int i=0; i<phoneNumber.size(); ++i)
		phoneNumberArr[i] = phoneNumber[i];

	for (int i=phoneNumber.size(); i<PNUM_SIZE; ++i)
		phoneNumberArr[i] = '\0';

	pb.AddPerson(firstName, lastName, nickName, darkestSecret, &phoneNumberArr[0]);
}

int main()
{
	PhoneBook pb;
	
	while (true)
	{
		std::string input;
		
		std::string a = "asd";
		std::string b = "asdf";
		
		std::cout << "== You can use following commands [ADD, SEARCH, EXIT] ==\n";
		std::cin >> input;

		if (input == "ADD")
			GetInfo(pb);
		else if (input == "SEARCH")
			pb.PrintPhoneBook();
		else if (input == "EXIT")
			return 0;
		else
			std::cout << "wrong command\n\n";
	}
}