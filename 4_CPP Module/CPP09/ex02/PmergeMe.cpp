/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:53 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/08 22:01:23 by kwsong           ###   ########.fr       */
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
	, set()
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
	, set(other.set)
	, argQue(other.argQue)
	, straggler(other.straggler)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	vec = other.vec;
	deq = other.deq;
	set = other.set;
	argQue = other.argQue;
	straggler = other.straggler;
	return *this;	
}

PmergeMe& PmergeMe::getInstance()
{
	static PmergeMe instance;
	return instance;
}

// ----- Static functions -----

template <typename T>
static void print(T& container)
{
	for (int i = 0; i < (int)container.size(); ++i)
		std::cout << container[i] << " ";
	std::cout << "\n";
}

static int jacobsthal(int n)
{
	if (n == 0 || n == 1)
		return n;

	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

static void getJacobSequence(int len, std::queue<int>& que)
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

static void swap(long& val1, long& val2)
{
	long temp = val1;
	val1 = val2;
	val2 = temp;
}

// sysconf(_SC_CLK_TCK);
static unsigned long ticksToMicroseconds(clock_t ticks)
{
	//std::cout << ticks << "\n";
    static double microsecondsPerTick = 1.0 / CLOCKS_PER_SEC * 1000000.0;
    return static_cast<unsigned long>(ticks * microsecondsPerTick);
}


// ----- Member functions -----

void PmergeMe::checkSuccess()
{
	if (set.size() != vec.size() || set.size() != deq.size())
		throw PmergeMe::Fail();

	std::set<long>::iterator iter = set.begin();
	for (int i = 0; iter != set.end(); ++iter, ++i)
	{
		if (*iter != vec[i] || *iter != deq[i])
			throw PmergeMe::Fail();
	}
}

template <typename T>
void PmergeMe::separate(const T& src, T& result, T& less)
{
	for (int i = 0; i < (int)src.size(); i += 2)
	{
		less.push_back(src[i]);
		result.push_back(src[i + 1]);
	}
}

template <typename T>
void PmergeMe::sortByPair(T& container)
{
	for (int i = 0; i < (int)container.size(); i += 2)
	{
		if (container[i] > container[i + 1])
			swap(container[i], container[i + 1]);
	}

	for (int i = 0; i < (int)container.size(); i += 2)
	{
		for (int j = i; j > 0; j -= 2)
		{
			if (container[j - 1] > container[j + 1])
			{
				swap(container[j - 1], container[j + 1]);
				swap(container[j - 2], container[j]);
			}
		}
	}
}

template <typename T>
void PmergeMe::getStraggler(T& container)
{
	if (container.size() % 2 == 1)
	{
		straggler.isExist = true;
		straggler.num = container.back();
		container.pop_back();
	}
}

template <typename T>
void PmergeMe::pushArgs(T& container)
{
	for (int i = 0; i < (int)argQue.size(); ++i)
		container.push_back(argQue[i]);
}

void PmergeMe::sortVector()
{
	clock_t begin = clock();

	pushArgs(vec);
	getStraggler(vec);
	sortByPair(vec);

	std::vector<long> result;
	std::vector<long> less;

	separate(vec, result, less);
	result.insert(result.begin(), less[0]);
	print(result);
	print(less);

	std::queue<int> jacob;
	getJacobSequence(less.size(), jacob);
	
	std::set<int> usedIndex;
	usedIndex.insert(0);
	
	int cur = 1;
	while (true)
	{
		if (usedIndex.find(cur - 1) != usedIndex.end())
		{
			if (jacob.empty())
				break;
			else
			{
				cur = jacob.front();
				jacob.pop();
			}
		}
		else
			cur -= 1;

		while (cur >= (int)less.size())
			--cur;
			
		usedIndex.insert(cur);
		std::vector<long>::iterator pos = std::upper_bound(result.begin(), result.end(), less[cur]);

		if (pos == result.end())
			result.push_back(less[cur]);
		else
			result.insert(pos, less[cur]);
	}

	if (straggler.isExist)
	{
		std::vector<long>::iterator pos = std::upper_bound(result.begin(), result.end(), straggler.num);

		if (pos == result.end())
			result.push_back(straggler.num);
		else
			result.insert(pos, straggler.num);
	}
	print(result);
	clock_t end = clock();
	unsigned long elapsedMicroseconds = ticksToMicroseconds(end - begin);
    std::cout <<  "Time to process a range of "<< result.size() << " elements with std::vector : "  << elapsedMicroseconds << " μs\n";

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
	result.push_front(less.front());
	less.pop_front();

	std::queue<int> jacob;
	getJacobSequence(less.size(), jacob);

	for (int i = 0; i < (int)less.size(); ++i)
	{
		std::deque<long>::iterator pos = std::upper_bound(result.begin(), result.end(), less[i]);

		if (pos == result.end())
			result.push_back(less[i]);
		else
			result.insert(pos, less[i]);
	}

	if (straggler.isExist)
	{
		std::deque<long>::iterator pos = std::upper_bound(result.begin(), result.end(), straggler.num);

		if (pos == result.end())
			result.push_back(straggler.num);
		else
			result.insert(pos, straggler.num);
	}
	
	clock_t end = clock();
	unsigned long elapsedMicroseconds = ticksToMicroseconds(end - begin);
    std::cout <<  "Time to process a range of "<< vec.size() << " elements with std::deque  : "  << elapsedMicroseconds << " μs\n";

	deq.swap(result);
}

void PmergeMe::printArgs()
{
	std::cout << "Before: ";
	for (int i = 0; i < (int)argQue.size(); ++i)
		std::cout << argQue[i] << " ";
	std::cout << "\n";

	std::cout << "After:  ";
	std::set<long>::iterator iter = set.begin();
	for (; iter != set.end(); ++iter)
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
			if (num < 0 || set.find(num) != set.end())
				throw PmergeMe::Error();
			
			set.insert(num);
			argQue.push_back(num);
			
			if (ss.eof())
				isValid = true;
		}
		if (!isValid)
			throw PmergeMe::Error();
		++i;
	}
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