/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:09:04 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 20:50:28 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
	: name("")
{
}

Character::Character(std::string name)
	: name(name)
{
}

Character::Character(const Character& other)
	: name(other.name)
{
}

Character::~Character()
{
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{
	
}