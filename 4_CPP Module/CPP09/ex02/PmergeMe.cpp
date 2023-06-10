/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:53 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/10 16:44:30 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::Straggler::Straggler()
	: isExist(false)
	, num (0)
{
}

PmergeMe::PmergeMe()
	: vec()
	, deq()
	, dupChecker()
	, argQue()
	, straggler()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: vec(other.vec)
	, deq(other.deq)
	, dupChecker(other.dupChecker)
	, argQue(other.argQue)
	, straggler(other.straggler)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	vec = other.vec;
	deq = other.deq;
	dupChecker = other.dupChecker;
	argQue = other.argQue;
	straggler = other.straggler;
	return *this;	
}

PmergeMe& PmergeMe::getInstance()
{
	static PmergeMe instance;
	return instance;
}

int PmergeMe::jacobsthal(int n)
{
	if (n == 0 || n == 1)
		return n;

	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::getJacobSequence(int len, std::queue<int>& que)
{
	int jacobIndex = 3;

	while (true)
	{
		int jacobNum = jacobsthal(jacobIndex) - 1;
		if (jacobNum >= len - 1)
		{
			que.push(jacobNum);
			break;
		}

		que.push(jacobNum);
		++jacobIndex;
	}
}

void PmergeMe::swap(long& val1, long& val2)
{
	long temp = val1;
	val1 = val2;
	val2 = temp;
}

void PmergeMe::checkSuccess()
{
	if (dupChecker.size() != vec.size() || dupChecker.size() != deq.size())
		throw PmergeMe::Fail();

	std::set<long>::iterator iter = dupChecker.begin();
	for (int i = 0; iter != dupChecker.end(); ++iter, ++i)
	{
		if (*iter != vec[i] || *iter != deq[i])
			throw PmergeMe::Fail();
	}
}

void PmergeMe::sortVector()
{
	clock_t begin = clock();

	vec.reserve(dupChecker.size());
	pushArgs(vec);
	getStraggler(vec);
	sortByPair(vec);

	std::vector<long> result;
	std::vector<long> less;

	result.reserve(vec.size());
	less.reserve(vec.size() / 2);
	
	separate(vec, result, less);
	if (!less.empty())
		result.insert(result.begin(), less[0]);
	
	merge(result, less);

	if (straggler.isExist)
		insertStraggler(result);

	clock_t end = clock();
    std::cout <<  "Time to process a range of "<< result.size() << " elements with std::vector : "  << end - begin << " μs\n";

	// std::cout << "result vector : ";
	// print(result);
	vec.swap(result);
}

void PmergeMe::sortDeque()
{
	clock_t begin = clock();

	pushArgs(deq);
	getStraggler(deq);
	sortByPair(deq);

	std::deque<long> result;
	std::deque<long> less;
	
	separate(deq, result, less);
	if (!less.empty())
		result.push_front(less.front());

	merge(result, less);

	if (straggler.isExist)
		insertStraggler(result);
	
	clock_t end = clock();
    std::cout <<  "Time to process a range of "<< vec.size() << " elements with std::deque  : "  << end - begin << " μs\n";

	// std::cout << "result deque  : ";
	// print(result);
	deq.swap(result);
}

void PmergeMe::printArgs()
{
	std::cout << "Before: ";
	for (int i = 0; i < (int)argQue.size(); ++i)
		std::cout << argQue[i] << " ";
	std::cout << "\n";

	std::cout << "After:  ";
	std::set<long>::iterator iter = dupChecker.begin();
	for (; iter != dupChecker.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << "\n";
}

// long_max = 9223372036854775807
void PmergeMe::parseArgs(char** strs)
{
	bool isValid;

	int i = 1;
	while (strs[i] != NULL)
	{
		std::stringstream ss(strs[i]);
		long num;
		isValid = false;
		
		while (ss >> num)
		{
			if (num < 0 || dupChecker.find(num) != dupChecker.end())
				throw PmergeMe::Error();
			
			dupChecker.insert(num);
			argQue.push_back(num);
			
			if (ss.eof())
				isValid = true;
		}
		if (!isValid)
			throw PmergeMe::Error();
		++i;
	}
	
	if (dupChecker.size() > 10000)
		throw PmergeMe::Error();
}

void PmergeMe::sort(char** strs)
{
	parseArgs(strs);
	printArgs();
	sortVector();
	sortDeque();
	try
	{
		checkSuccess();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}


// ----- Exception -----

const char* PmergeMe::Error::what() const throw()
{
	return "Error\n";
}

const char* PmergeMe::Fail::what() const throw()
{
	return "Failed to sort\n";
}