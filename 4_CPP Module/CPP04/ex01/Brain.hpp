/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:47:55 by kwsong            #+#    #+#             */
/*   Updated: 2023/07/10 12:39:07 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>

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
	const std::string& GetIdea(unsigned int index) const;
};