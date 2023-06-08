/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:53 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/08 17:07:29 by kwsong           ###   ########.fr       */
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

template <typename T>
void getJacobSequence(int len, T& jacob)
{
	
}

template <typename T>
void separate(const T& src, T& result, T& less)
{
	for (int i = 0; i < (int)container.size(); i += 2)
	{
		less.push_back(src[i]);
		result.push_back(src[i + 1]);
	}
}

template <typename T>
void PmergeMe::sortByPair(T& container)
{
	print(container);
	for (int i = 0; i < (int)container.size(); i += 2)
	{
		if (container[i] > container[i + 1])
			swap(container[i], container[i + 1]);
	}

	print(container);
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
	print(container);
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
	less.erase(less.begin());

	std::vector<int> jacob;
	getJacobSequence(less.size(), jacob);

	clock_t end = clock();
	unsigned long elapsedMicroseconds = ticksToMicroseconds(end - begin);
    std::cout <<  "Time to process a range of "<< vec.size() << " elements with std::vector : "  << elapsedMicroseconds << "\n";
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

	

	clock_t end = clock();
	unsigned long elapsedMicroseconds = ticksToMicroseconds(end - begin);
    std::cout <<  "Time to process a range of "<< vec.size() << " elements with std::deargQue  : "  << elapsedMicroseconds << "\n";
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
}


// ----- Exception -----

const char* PmergeMe::Error::what() const throw()
{
	return "Error\n";
}