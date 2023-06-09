/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:51 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/09 16:33:32 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <exception>
#include <ctime>
#include <algorithm>

class PmergeMe
{
private:
	struct Straggler
	{
	public:
		bool isExist;
		long num;
		
	public:
		Straggler();
	};

private:
	std::vector<long> vec;
	std::deque<long> deq;
	std::set<long> dupChecker;
	std::deque<long> argQue;
	Straggler straggler;

private:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& other);

private:
	int jacobsthal(int n);
	void getJacobSequence(int len, std::queue<int>& que);
	void swap(long& val1, long& val2);
	template <typename T> void print(T& container);
	template <typename T> void insertStraggler(T& result);
	template <typename T> void merge(T& result, T& less);
	template <typename T> void pushArgs(T& container);
	template <typename T> void getStraggler(T& container);
	template <typename T> void sortByPair(T& container);
	template <typename T> void separate(const T& src, T& result, T& less);
	void parseArgs(char** strs);
	void printArgs();
	void sortVector();
	void sortDeque();
	void checkSuccess();

public:
	static PmergeMe& getInstance();
	void sort(char** strs);

public:
	class Error : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class Fail : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

template <typename T>
void PmergeMe::print(T& container)
{
	for (int i = 0; i < (int)container.size(); ++i)
		std::cout << container[i] << " ";
	std::cout << "\n";
}

template <typename T>
void PmergeMe::insertStraggler(T& result)
{
	typename T::iterator pos = std::upper_bound(result.begin(), result.end(), straggler.num);

	if (pos == result.end())
		result.push_back(straggler.num);
	else
		result.insert(pos, straggler.num);
}

template <typename T>
void PmergeMe::merge(T& result, T& less)
{
	if (less.size() <= 1)
		return;
		
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

		if (cur >= (int)less.size())
			cur = (int)less.size() - 1;
			
		usedIndex.insert(cur);
		typename T::iterator pos = std::upper_bound(result.begin(), result.end(), less[cur]);

		if (pos == result.end())
			result.push_back(less[cur]);
		else
			result.insert(pos, less[cur]);
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