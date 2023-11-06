/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:49:03 by kwsong            #+#    #+#             */
/*   Updated: 2023/11/06 21:42:54 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
}

MateriaSource::~MateriaSource()
{
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	this->inventory = other.inventory;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (&other != this)
		this->inventory = other.inventory;
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
		return;
	
	inventory.AddItem(m);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (unsigned int i = 0; i < inventory.GetCapacity(); ++i)
	{
		const AMateria* targetSlot = inventory.GetSlot(i);

		if (targetSlot != NULL && type == targetSlot->getType())
			return targetSlot->clone();
	}
	return NULL;
}