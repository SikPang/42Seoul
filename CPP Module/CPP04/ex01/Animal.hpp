/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:54:40 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 19:16:09 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>
#include "Brain.hpp"

class Animal
{
protected:
	std::string	type;
	Brain*		brain;

public:
	Animal();
	Animal(Animal& instance);
	virtual ~Animal();
	Animal&			operator=(Animal& instance);

	virtual void	makeSound() const;
	std::string		getType() const;
};

#endif