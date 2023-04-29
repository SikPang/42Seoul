/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:05:24 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 19:38:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain*	brain;

public:
	Cat();
	Cat(const Cat& other);
	~Cat();
	Cat& operator=(const Cat& other);

public:
	void makeSound() const;	// override
	unsigned int GetSizeOfIdeas() const;
	void AddIdea(const std::string& idea, unsigned int index);
	std::string GetIdea(unsigned int index) const;
};