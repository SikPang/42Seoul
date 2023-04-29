/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:54:40 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 19:38:50 by kwsong           ###   ########.fr       */
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
	Animal(const Animal& other);
	virtual ~Animal();
	Animal&	operator=(const Animal& other);

public:
	virtual void	makeSound() const;
	std::string		getType() const;
};