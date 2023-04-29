/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:47:55 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 17:19:22 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <string>

#define IDEA_CAPACITY 100

class Brain
{
private:
	std::string ideas[IDEA_CAPACITY];
	unsigned int size;

public:
	Brain();
	Brain(const Brain& other);
	~Brain();
	Brain&	operator=(const Brain& other);

public:
	unsigned int GetSize() const;
	void AddIdea(const std::string& idea, unsigned int index);
	std::string GetIdea(unsigned int index) const;
	void duplicate(const Brain* other);
};

#endif