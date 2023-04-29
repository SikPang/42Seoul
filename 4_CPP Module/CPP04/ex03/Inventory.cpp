/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:46:45 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 20:54:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inventory.hpp"

Inventory::Inventory()
	: capacity(SIZE_OF_INVENTORY)
	, size(0)
{
}

Inventory::Inventory(const Inventory& other)
	: capacity(other.capacity)
	, size(other.size)
{
}

Inventory::~Inventory()
{
}

Inventory& Inventory::operator=(const Inventory& other)
{
	capacity = other.capacity;
	size = other.size;
}