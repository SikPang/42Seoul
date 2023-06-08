/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:51 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/08 16:27:46 by kwsong           ###   ########.fr       */
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
	std::set<long> set;
	std::deque<long> argQue;
	Straggler straggler;

private:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& other);

private:
	template <typename T> void pushArgs(T& container);
	template <typename T> void getStraggler(T& container);
	template <typename T> void sortByPair(T& container);
	void parseArgs(char** strs);
	void printArgs();
	void sortVector();
	void sortDeque();

public:
	static PmergeMe& getInstance();
	void sort(char** strs);

public:
	class Error : public std::exception
	{
	public:
		const char* what() const throw();
	};
};