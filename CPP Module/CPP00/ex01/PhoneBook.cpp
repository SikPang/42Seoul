/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:13:20 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/14 19:13:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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

void PhoneBook::AddPerson(std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret, char *phoneNumber)
{
	Person person(firstName, lastName, nickName, darkestSecret, phoneNumber);
	
	if (size == 0)
	{
		head = 0;
		tail = 0;
		list[tail] = person;
	}
	else
	{
		tail += 1;
		if (tail == PB_SIZE)
			tail = 0;
		list[tail] = person;
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

void PhoneBook::RemovePerson()
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

void PhoneBook::PrintPhoneBook()
{
	int		index;
	char*	phoneNumber;
	
	for (int i=0; i<size; ++i)
	{
		std::cout << i << "\t" 
			<< list[(head + i) % PB_SIZE].GetFirstName() << "\t"
			<< list[(head + i) % PB_SIZE].GetLastName() << "\t"
			<< list[(head + i) % PB_SIZE].GetNickName() << "\t";
	}
	std::cout << "Put index to see the phone number\n";
	std::cin >> index;

	phoneNumber = list[(head + index) % PB_SIZE].GetPhoneNumber();
	for (int i=0; i<PNUM_SIZE; ++i)
		std::cout << phoneNumber[i];
	std::cout << '\n';
}

PhoneBook::~PhoneBook() {}


// ----- Inner class -----
PhoneBook::Person::Person()
{
	firstName = "";
	lastName = "";
	nickName = "";
	darkestSecret = "";
	for (int i = 0; i < PNUM_SIZE; ++i)
		phoneNumber[i] = '\0';
}

PhoneBook::Person::Person(const Person& instance)
{
	firstName = instance.firstName;
	lastName = instance.lastName;
	nickName = instance.nickName;
	darkestSecret = instance.darkestSecret;
	for (int i = 0; i < PNUM_SIZE; ++i)
		phoneNumber[i] = instance.phoneNumber[i];
}

PhoneBook::Person::Person(std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret, char *phoneNumber)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->darkestSecret = darkestSecret;
	for (int i = 0; i < PNUM_SIZE; ++i)
		this->phoneNumber[i] = phoneNumber[i];
}

PhoneBook::Person& PhoneBook::Person::operator=(const Person& instance)
{
	firstName = instance.firstName;
	lastName = instance.lastName;
	nickName = instance.nickName;
	darkestSecret = instance.darkestSecret;
	for (int i = 0; i < PNUM_SIZE; ++i)
		phoneNumber[i] = instance.phoneNumber[i];
	return *this;
}

PhoneBook::Person::~Person() {}

std::string PhoneBook::Person::GetFirstName()
{
	return firstName;
}

std::string PhoneBook::Person::GetLastName()
{
	return lastName;
}

std::string PhoneBook::Person::GetNickName()
{
	return nickName;
}

char* PhoneBook::Person::GetPhoneNumber()
{
	return &phoneNumber[0];
}