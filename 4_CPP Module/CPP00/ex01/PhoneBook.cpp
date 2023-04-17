/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:13:20 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/17 20:10:57 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

// ----- Outer class -----
PhoneBook::PhoneBook()
{
	head = -1;
	tail = -1;
	size = 0;
}

PhoneBook::PhoneBook(const PhoneBook& instance)
{
	head = instance.head;
	tail = instance.tail;
	size = instance.size;
}

PhoneBook& PhoneBook::operator=(const PhoneBook& instance)
{
	head = instance.head;
	tail = instance.tail;
	size = instance.size;	
	return *this;
}

void PhoneBook::AddContact(std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret, char *phoneNumber)
{
	Contact Contact(firstName, lastName, nickName, darkestSecret, phoneNumber);
	
	if (size == 0)
	{
		head = 0;
		tail = 0;
		list[tail] = Contact;
	}
	else
	{
		tail += 1;
		if (tail == PB_SIZE)
			tail = 0;
		list[tail] = Contact;
		if (size == PB_SIZE)
		{
			head += 1;
			if (head == PB_SIZE)
				head = 0;
			--size;
		}
	}
	++size;
}

void PhoneBook::RemoveContact()
{
	if (size == 0)
		return;
	else if (size == 1)
	{
		head = -1;
		tail = -1;
	}
	else
	{
		tail -= 1;
		if (tail < 0)
			tail = PB_SIZE - 1;
	}
	--size;
}

static void PrintLimits(const std::string& str)
{
	if (str.size() > 10)
		std::cout << std::right << std::setw(9) << str.substr(0, 9) << '.';
	else
		std::cout << std::right << std::setw(10) << str;
}

void PhoneBook::PrintPhoneBook()
{
	if (size == 0)
	{
		std::cout << CYN << "There is no one in PhoneBook\n\n" << NC;
		return;
	}
	
	int		index;

	std::cout << '\n';
	
	std::cout << CYN << std::right << std::setw(11) << "index|" << std::setw(11) << "FirstName|"
		<< std::setw(11) << "LastName|" << std::setw(11) << "NickName\n" << NC;
	for (int i=0; i<size; ++i)
	{
		std::cout << std::right << std::setw(10) << i << "|";
		PrintLimits(list[(head + i) % PB_SIZE].GetFirstName());
		std::cout << '|';
		PrintLimits(list[(head + i) % PB_SIZE].GetLastName());
		std::cout << '|';
		PrintLimits(list[(head + i) % PB_SIZE].GetNickName());
		std::cout << '\n';
	}
	
	while (true)
	{
		std::cout << CYN << "\n== Put index to see the phone number ==\n" << NC;
		std::cin >> index;
		if (std::cin.fail())
		{
			std::cin.clear();
			index = -1;
		}
		std::cin.ignore(INT_MAX, '\n');

		if (index < 0 || index >= size)
			std::cout << RED << "wrong index\n\n" << NC;
		else
			break;
	}

	std::cout << RED << list[(head + index) % PB_SIZE].GetNickName() << "'s Phone Number is ";
	for (int i=0; i<PNUM_SIZE; ++i)
		std::cout << list[(head + index) % PB_SIZE].GetPhoneNumber()[i];
	std::cout << "\n\n" << NC;
}

PhoneBook::~PhoneBook() {}


// ----- Inner class -----
PhoneBook::Contact::Contact()
{
	firstName = "";
	lastName = "";
	nickName = "";
	darkestSecret = "";
	for (int i = 0; i < PNUM_SIZE; ++i)
		phoneNumber[i] = '\0';
}

PhoneBook::Contact::Contact(const Contact& instance)
{
	firstName = instance.firstName;
	lastName = instance.lastName;
	nickName = instance.nickName;
	darkestSecret = instance.darkestSecret;
	for (int i = 0; i < PNUM_SIZE; ++i)
		phoneNumber[i] = instance.phoneNumber[i];
}

PhoneBook::Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret, char *phoneNumber)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->darkestSecret = darkestSecret;
	for (int i = 0; i < PNUM_SIZE; ++i)
		this->phoneNumber[i] = phoneNumber[i];
}

PhoneBook::Contact& PhoneBook::Contact::operator=(const Contact& instance)
{
	firstName = instance.firstName;
	lastName = instance.lastName;
	nickName = instance.nickName;
	darkestSecret = instance.darkestSecret;
	for (int i = 0; i < PNUM_SIZE; ++i)
		phoneNumber[i] = instance.phoneNumber[i];
	return *this;
}

PhoneBook::Contact::~Contact() {}

const std::string& PhoneBook::Contact::GetFirstName()
{
	return firstName;
}

const std::string& PhoneBook::Contact::GetLastName()
{
	return lastName;
}

const std::string& PhoneBook::Contact::GetNickName()
{
	return nickName;
}

const char* PhoneBook::Contact::GetPhoneNumber()
{
	return &phoneNumber[0];
}