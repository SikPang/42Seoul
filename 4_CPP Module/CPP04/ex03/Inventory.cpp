/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:46:45 by kwsong            #+#    #+#             */
/*   Updated: 2023/11/06 22:25:30 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inventory.hpp"

Inventory::Inventory()
{
	for (unsigned int i = 0; i < MAX_SIZE_OF_INVENTORY; ++i)
		this->slots[i] = NULL;
}

Inventory::Inventory(const Inventory& other)
{
	CopyAllItems(other);
}

Inventory::~Inventory()
{
	DeleteAllItems();
}

Inventory& Inventory::operator=(const Inventory& other)
{
	if (&other == this)
		return *this;
	
	DeleteAllItems();
	CopyAllItems(other);

	return *this;
}

unsigned int Inventory::GetCapacity() const
{
	return MAX_SIZE_OF_INVENTORY;
}

void Inventory::AddItem(AMateria* m)
{
	for (unsigned int i = 0; i < MAX_SIZE_OF_INVENTORY; ++i)
	{
		if (slots[i] == NULL)
		{
			slots[i] = m;
			return;
		}
	}
}

void Inventory::RemoveItem(unsigned int index)
{
	if (index >= MAX_SIZE_OF_INVENTORY)
		throw std::exception();

	slots[index] = NULL;
}

AMateria* Inventory::GetSlot(unsigned int index) const
{
	if (index >= MAX_SIZE_OF_INVENTORY)
		throw std::exception();

	return slots[index];
}


// --- private memeber functions ---

void Inventory::CopyAllItems(const Inventory& other)
{
	for (unsigned int i = 0; i < other.GetCapacity(); ++i)
	{
		if (other.slots[i])
			this->slots[i] = other.slots[i]->clone();
		else
			this->slots[i] = NULL;
	}
}

void Inventory::DeleteAllItems()
{
	for (unsigned int i = 0; i < MAX_SIZE_OF_INVENTORY; ++i)
	{
		if (this->slots[i])
			delete this->slots[i];
	}
}