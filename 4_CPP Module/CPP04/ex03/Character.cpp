/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:09:04 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/30 09:32:29 by kwsong           ###   ########.fr       */
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
	this->inventory = other.inventory;
}

Character::~Character()
{
}

Character& Character::operator=(const Character& other)
{
	if (&other != this)
		this->inventory = other.inventory;
	return *this;
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		return;
	
	inventory.AddItem(m);
}

void Character::unequip(int idx)
{
	if (idx < 0)
		return;
	
	inventory.RemoveItem(idx);
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0)
		return;
	
	AMateria* selected = inventory.GetSlot(idx);
	
	if (selected != NULL)
		selected->use(target);
}

unsigned int Character::GetSizeOfInventory()
{
	return inventory.GetSize();
}

unsigned int Character::GetCapacityOfInventory()
{
	return inventory.GetCapacity();
}