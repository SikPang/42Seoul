/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:46:45 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/30 09:32:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inventory.hpp"

Inventory::Inventory()
	: capacity(MAX_SIZE_OF_INVENTORY)
	, size(0)
{
}

Inventory::Inventory(const Inventory& other)
	: capacity(other.capacity)
	, size(other.size)
{
	for (unsigned int i = 0; i < other.size; ++i)
	{
		if (dynamic_cast<Ice*>(other.slots[i]))
			this->slots[i] = new Ice();
		else
			this->slots[i] = new Cure();
	}
}

Inventory::~Inventory()
{
	for (unsigned int i = 0; i < size; ++i)
		delete this->slots[i];
}

Inventory& Inventory::operator=(const Inventory& other)
{
	if (&other == this)
		return *this;
	
	for (unsigned int i = 0; i < other.size; ++i)
		delete this->slots[i];

	for (unsigned int i = 0; i < other.size; ++i)
	{
		if (dynamic_cast<Ice*>(other.slots[i]))
			this->slots[i] = new Ice();
		else
			this->slots[i] = new Cure();
	}
	
	capacity = other.capacity;
	size = other.size;

	return *this;
}

unsigned int Inventory::GetCapacity()
{
	return capacity;
}

unsigned int Inventory::GetSize()
{
	return size;
}

void Inventory::AddItem(AMateria* m)
{
	if (size == capacity)
		return;

	slots[size++] = m;
}

void Inventory::RemoveItem(unsigned int index)
{
	if (index >= size)
		return;

	slots[--size] = NULL;
}

AMateria* Inventory::GetSlot(unsigned int index)
{
	if (index >= size)
		return NULL;

	return slots[index];
}