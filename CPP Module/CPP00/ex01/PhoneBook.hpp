/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:13:18 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/14 14:47:27 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "List.hpp"

#define PNUM_SIZE 20
#define PB_SIZE 8

class PhoneBook
{
private:
	class Person
	{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	darkestSecret;
		char		phoneNumber[PNUM_SIZE];
	public:
		Person();
		Person(const Person& instance);
		Person(std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret, char *phoneNumber);
		~Person();
		Person& operator=(const Person& instance);
	};

private:
	List<Person>	list;
	int				head;
	int				tail;
	int				size;
	
public:
	PhoneBook();
	PhoneBook(const PhoneBook& instance);
	~PhoneBook();
	PhoneBook& operator=(const PhoneBook& instance);

	void AddPerson(std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret, char *phoneNumber);
	void RemovePerson();
	void PrintPhoneBook();
};