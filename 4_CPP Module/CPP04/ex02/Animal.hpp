/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:54:40 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 17:44:11 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal
{
protected:
	std::string	type;

public:
	Animal();
	Animal(const Animal& instance);
	virtual ~Animal();
	Animal&	operator=(const Animal& instance);

public:
	virtual void	makeSound() const = 0;
	std::string		getType() const;
};