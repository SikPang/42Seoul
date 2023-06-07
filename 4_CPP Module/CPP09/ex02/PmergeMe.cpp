/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:53 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/07 21:34:13 by kwsong           ###   ########.fr       */
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

/*
def main():
  S = [123, 56, 45, 346, 14, 12, 312, 5, 57, 7, 9, 7856]
  merge_insertion_sort(S)


if __name__ == "__main__":
  main()
*/

void PmergeMe::sort()
{
	/*
	1. 홀수면 straggler 정하기
	2. 2개씩 짝짓기
	3. 짝끼리 정렬
	4. 각 쌍의 큰 수 비교 정렬
	5. 각 쌍에서 큰 수는 S, 작은 수는 pend로 옮기기
	6. 
	*/
}


// ----- Exception -----

const char* PmergeMe::Error::what() const throw()
{
	return "Error\n";
}