/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:54:40 by kwsong            #+#    #+#             */
/*   Updated: 2023/11/06 20:14:27 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Animal
{
protected:
	std::string	type;

public:
	Animal();
	Animal(const Animal& other);
	Animal(const std::string& type);
	virtual ~Animal();
	Animal& operator=(const Animal& other);

public:
	virtual void makeSound() const = 0;
	const std::string& getType() const;
};