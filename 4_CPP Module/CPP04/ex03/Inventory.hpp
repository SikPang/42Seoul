/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:46:47 by kwsong            #+#    #+#             */
/*   Updated: 2023/11/06 21:40:30 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#define MAX_SIZE_OF_INVENTORY 4

class Inventory
{
private:
	AMateria* slots[MAX_SIZE_OF_INVENTORY];

private:
	void CopyAllItems(const Inventory& other);
	void DeleteAllItems();

public:
	Inventory();
	Inventory(const Inventory& other);
	~Inventory();
	Inventory& operator=(const Inventory& other);

public:
	unsigned int GetCapacity() const;
	void AddItem(AMateria* m);
	void RemoveItem(unsigned int index);
	AMateria* GetSlot(unsigned int index) const;
};