/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:51 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/06 20:50:42 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <set>
#include <iostream>
#include <sstream>
#include <exception>

class PmergeMe
{
private:
	std::vector<long> vec;
	std::deque<long> deq;
	std::set<long> set;

private:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& other);

public:
	static PmergeMe& getInstance();
	void setArgs(int ac, char** str);
	void sort();

public:
	class Error : public std::exception
	{
	public:
		const char* what() const throw();
	};
};