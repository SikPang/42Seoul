/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:43:08 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/07 12:15:47 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
	: data()
{
	srand(time(NULL));
}

Span::Span(unsigned int capacity)
{
	srand(time(NULL));
	data.reserve(capacity);
}

Span::Span(const Span& other)
	: data(other.data)
{
	srand(time(NULL));
}

Span::~Span()
{
}

Span& Span::operator=(const Span& other)
{
	if (&other == this)
		return *this;

	data.swap(const_cast<std::vector<int>&>(other.data));
	return *this;
}

int& Span::operator[](unsigned int index)
{
	if (index >= data.size())
		throw LengthException();

	return data[index];
}

void Span::addNumber(int num)
{
	if (data.size() == data.capacity())
		throw TooManyElements();

	data.push_back(num);
}

void Span::fillNumbers()
{
	if (data.size() == data.capacity())
		throw TooManyElements();
	
	int randNum;
	int size = (int)data.size();
	int capacity = (int)data.capacity();
	int range = data.capacity() * 10;
	for (int i = size; i < capacity; ++i)
	{
		int sign = rand() % 2;
		if (sign == 0)
			randNum = -(rand() % range);
		else
			randNum = rand() % range;

		data.push_back(randNum);
	}
}

void Span::insert(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end)
{
	if (begin >= end)
		throw WrongIterator();
	
	if (data.capacity() == data.size()
		|| (unsigned long)(end - begin) > (unsigned long)(data.capacity() - data.size()))
		throw TooManyElements();
	data.insert(data.end(), begin, end);
}

int Span::shortestSpan()
{
	if (data.size() < 2)
		throw TooFewElements();
	
	std::sort(data.begin(), data.end());

	std::vector<int> temp1(data.size());
	std::adjacent_difference(data.begin(), data.end(), temp1.begin());

	std::vector<int>::iterator iter = std::min_element(temp1.begin() + 1, temp1.end());
	int index = iter - (temp1.begin() + 1);

	//std::cout << data[index] << ", " << data[index + 1] << " -> "; 

	return std::abs(data[index] - data[index + 1]);
}

int Span::longestSpan()
{
	if (data.size() < 2)
		throw TooFewElements();
	
	std::sort(data.begin(), data.end());

	//std::cout <<  data[0] << ", " << data[data.size() - 1] << " -> "; 
	
	return std::abs(data[0] - data[data.size() - 1]);
}

void Span::sort()
{
	std::sort(data.begin(), data.end());
}

void Span::print()
{
	int size = data.size();
	for (int i = 0; i < size; ++i)
		std::cout << data[i] << " ";
	std::cout << "\n";
}


// ----- Exception -----

const char* Span::LengthException::what() const throw()
{
	return "out of index\n";
}

const char* Span::WrongIterator::what() const throw()
{
	return "wrong iterator\n";
}

const char* Span::TooManyElements::what() const throw()
{
	return "too many elements\n";
}

const char* Span::TooFewElements::what() const throw()
{
	return "too few elements\n";
}