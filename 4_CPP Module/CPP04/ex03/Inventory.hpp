/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:46:47 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 20:56:26 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

#define SIZE_OF_INVENTORY 4

class Inventory
{
private:
	AMateria* slots;
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
	void AddToSlot();
	AMateria* GetSlot();
};