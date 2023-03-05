/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:05:50 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/15 18:38:40 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	type = "";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon(Weapon& instance)
{
	type = instance.type;
}

Weapon& Weapon::operator=(Weapon& instance)
{
	type = instance.type;
	return *this;
}

Weapon::~Weapon() {}

const std::string& Weapon::getType()
{
	return (type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}