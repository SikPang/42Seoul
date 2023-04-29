/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:46:47 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/30 08:05:26 by kwsong           ###   ########.fr       */
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
	unsigned int capacity;
	unsigned int size;

public:
	Inventory();
	Inventory(const Inventory& other);
	~Inventory();
	Inventory& operator=(const Inventory& other);

public:
	unsigned int GetCapacity();
	unsigned int GetSize();
	void AddItem(AMateria* m);
	void RemoveItem(unsigned int index);
	AMateria* GetSlot(unsigned int index);
};