/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:13:18 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/17 20:10:23 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <string>

#define PNUM_SIZE 21
#define PB_SIZE 8
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"

class PhoneBook
{
private:
	class Contact
	{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	darkestSecret;
		char		phoneNumber[PNUM_SIZE];

	public:
		Contact();
		Contact(const Contact& instance);
		Contact(std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret, char *phoneNumber);
		~Contact();
		Contact&		operator=(const Contact& instance);
		const std::string&	GetFirstName();
		const std::string&	GetLastName();
		const std::string&	GetNickName();
		const char*			GetPhoneNumber();
	};

private:
	Contact	list[PB_SIZE];
	int		head;
	int		tail;
	int		size;

public:
	PhoneBook();
	PhoneBook(const PhoneBook& instance);
	~PhoneBook();
	PhoneBook& operator=(const PhoneBook& instance);

	void AddContact(std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret, char *phoneNumber);
	void RemoveContact();
	void PrintPhoneBook();
};

#endif