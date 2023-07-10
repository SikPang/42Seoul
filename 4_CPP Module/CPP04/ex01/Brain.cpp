/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:47:57 by kwsong            #+#    #+#             */
/*   Updated: 2023/07/10 12:39:25 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain()
	: size(IDEA_CAPACITY)
{
	for (unsigned int i = 0; i < size; ++i)
		ideas[i] = "";

	std::cout << "Brain Created.\n";
}

Brain::Brain(const Brain& other)
	: size(other.size)
{
	for (unsigned int i = 0; i < size; ++i)
		ideas[i] = other.ideas[i];

	std::cout << "Brain Created.\n";
}

Brain& Brain::operator=(const Brain& other)
{
	if (&other == this)
		return *this;
	
	for (unsigned int i = 0; i < size; ++i)
		ideas[i] = other.ideas[i];
	size = other.size;
	
	return *this;
}

Brain::~Brain() 
{
	std::cout << "Brain Destroyed.\n";
}

unsigned int Brain::GetSize() const
{
	return size;
}

void Brain::AddIdea(const std::string& idea, unsigned int index)
{
	if (index >= size)
		return;
	
	ideas[index] = idea;
}

const std::string& Brain::GetIdea(unsigned int index) const
{
	if (index >= size)
		throw std::exception();

	return ideas[index];
}