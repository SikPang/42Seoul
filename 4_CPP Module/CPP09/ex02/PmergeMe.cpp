/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:53 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/06 20:45:52 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
	: vec()
	, deq()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: vec(other.vec)
	, deq(other.deq)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	vec = other.vec;
	deq = other.deq;
	return *this;	
}

PmergeMe& PmergeMe::getInstance()
{
	static PmergeMe instance;
	return instance;
}

// long_max = 9223372036854775807
void PmergeMe::setArgs(int ac, char** str)
{
	bool isValid;
	
	for (int i = 1; i < ac; ++i)
	{
		std::stringstream ss(str[i]);
		long num;
		isValid = false;
		
		while (ss >> num)
		{
			if (num < 0 || set.find(num) != set.end())
				throw PmergeMe::Error();

			vec.push_back(num);
			deq.push_back(num);
			set.insert(num);
			
			if (ss.eof())
				isValid = true;
		}
		if (!isValid)
			throw PmergeMe::Error();
	}
}

void PmergeMe::sort()
{
	
}


// ----- Exception -----

const char* PmergeMe::Error::what() const throw()
{
	return "Error\n";
}