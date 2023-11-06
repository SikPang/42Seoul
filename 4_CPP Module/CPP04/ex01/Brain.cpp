/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:47:57 by kwsong            #+#    #+#             */
/*   Updated: 2023/11/06 19:43:36 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	for (unsigned int i = 0; i < IDEA_CAPACITY; ++i)
		ideas[i] = "";

	std::cout << "Brain Created.\n";
}

Brain::Brain(const Brain& other)
{
	for (unsigned int i = 0; i < IDEA_CAPACITY; ++i)
		ideas[i] = other.ideas[i];

	std::cout << "Brain Created.\n";
}

Brain& Brain::operator=(const Brain& other)
{
	if (&other == this)
		return *this;
	
	for (unsigned int i = 0; i < IDEA_CAPACITY; ++i)
		ideas[i] = other.ideas[i];
	
	return *this;
}

Brain::~Brain() 
{
	std::cout << "Brain Destroyed.\n";
}

unsigned int Brain::GetSize() const
{
	return IDEA_CAPACITY;
}

void Brain::AddIdea(const std::string& idea, unsigned int index)
{
	if (index >= IDEA_CAPACITY)
		throw std::exception();
	
	ideas[index] = idea;
}

const std::string& Brain::GetIdea(unsigned int index) const
{
	if (index >= IDEA_CAPACITY)
		throw std::exception();

	return ideas[index];
}