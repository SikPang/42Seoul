/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:53 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/08 15:49:48 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
	: vec()
	, deq()
	, set()
	, printQue()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: vec(other.vec)
	, deq(other.deq)
	, set(other.set)
	, printQue(other.printQue)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	vec = other.vec;
	deq = other.deq;
	set = other.set;
	printQue = other.printQue;
	return *this;	
}

PmergeMe& PmergeMe::getInstance()
{
	static PmergeMe instance;
	return instance;
}

// sysconf(_SC_CLK_TCK);
static unsigned long ticksToMicroseconds(clock_t ticks)
{
	//std::cout << ticks << "\n";
    static double microsecondsPerTick = 1.0 / CLOCKS_PER_SEC * 1000000.0;
    return static_cast<unsigned long>(ticks * microsecondsPerTick);
}

template <typename T>
void PmergeMe::pushArgs(T& container)
{
	std::set<long>::iterator iter = set.begin();
	for (; iter != set.end(); ++iter)
		container.push_back(*iter);
}

void PmergeMe::sortVector()
{
	clock_t begin = clock();

	pushArgs(vec);
	

	clock_t end = clock();
	unsigned long elapsedMicroseconds = ticksToMicroseconds(end - begin);
    std::cout <<  "Time to process a range of "<< vec.size() << " elements with std::vector : "  << elapsedMicroseconds << "\n";
}

void PmergeMe::sortDeque()
{
	clock_t begin = clock();

	pushArgs(deq);
		

	clock_t end = clock();
	unsigned long elapsedMicroseconds = ticksToMicroseconds(end - begin);
    std::cout <<  "Time to process a range of "<< vec.size() << " elements with std::deque  : "  << elapsedMicroseconds << "\n";
}

void PmergeMe::printArgs()
{
	std::cout << "Before: ";
	while (!printQue.empty())
	{
		long cur = printQue.front();
		std::cout << cur << " ";
		printQue.pop();
	}
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
			printQue.push(num);
			
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
	/*
	1. 홀수면 straggler 정하기
	2. 2개씩 짝짓기
	3. 짝끼리 정렬
	4. 각 쌍의 큰 수 비교 정렬
	5. 각 쌍에서 큰 수는 S, 작은 수는 pend로 옮기기
	6. pend의 첫 요소를 S에 넣기 (첫 쌍의 작은 수는 항상 첫 쌍의 큰 수보다 작기 때문)
	7. pend의 길이에 따라서 Jacobsthal Number 수열 구하기 ( Jn = Jn-1 + 2 * Jn-2) 
	8. index[]에 1 넣어둠
	9. pend를 반복
		만약 Jacob[]이 남아있으면서 && 플래그가 아니면
			index[]에 Jacob 수열의 첫번째를 push_back
			pend[Jacob 수열의 첫번째 - 1] 값을 가져옴
			Jacob[]의 첫번째를 pop
			플래그 세움
		아니면
			index[]을 순회하며 반복자와 같은 요소가 있다면 반복자 +=1
			pend[반복자 - 1] 값을 가져옴
			index[]에 반복자를 push_back
			플래그 초기화
		S에서 가져온 값이 어디에 들어가야 하는지 이진탐색 후 insert
		반복자 += 1
		JacobIndex +=1
	10. 만약 straggler가 있다면 S에 이진탐색 후 insert
	*/
	parseArgs(strs);
	printArgs();
	sortVector();
	sortDeque();
}


// ----- Exception -----

const char* PmergeMe::Error::what() const throw()
{
	return "Error\n";
}