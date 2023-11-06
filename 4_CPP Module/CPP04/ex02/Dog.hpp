/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:07:15 by kwsong            #+#    #+#             */
/*   Updated: 2023/07/10 12:38:00 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;

public:
	Dog();
	Dog(const Dog& other);
	~Dog();
	Dog& operator=(const Dog& other);

public:
	void makeSound() const;	// override
	void AddIdea(const std::string& idea, unsigned int index);
	const std::string& GetIdea(unsigned int index) const;
};