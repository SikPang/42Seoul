/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:47:57 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/26 21:25:52 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	for (int i =0; i<IDEA_CAPACITY; ++i)
		ideas[i] = "";

	std::cout << "Brain Created.\n";
}

Brain::Brain(const Brain& instance)
{
	for (int i =0; i<IDEA_CAPACITY; ++i)
		ideas[i] = instance.ideas[i];

	std::cout << "Brain Created.\n";
}

Brain& Brain::operator=(const Brain& instance)
{
	for (int i =0; i<IDEA_CAPACITY; ++i)
		ideas[i] = instance.ideas[i];
	
	return *this;
}

Brain::~Brain() 
{
	std::cout << "Brain Destroyed.\n";
}