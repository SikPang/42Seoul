/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:43:06 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/29 21:58:40 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstdlib>

class Span
{
private:
	std::vector<int> data;
	
public:
	Span();
	Span(unsigned int capacity);
	Span(const Span& other);
	~Span();
	Span& operator=(const Span& other);
	int operator[](unsigned int index) const;

public:
	void addNumber(int num);
	int shortestSpan();
	int longestSpan();
	void fillNumbers();
	void insert(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
	void sortAndPrint();

public:
	class LengthException : public std::exception{};
	class WrongIterator : public std::exception{};
	class TooManyElements : public std::exception{};
	class TooFewElements : public std::exception{};
};