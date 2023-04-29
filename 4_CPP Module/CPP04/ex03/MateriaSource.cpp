/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:49:03 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/30 08:47:33 by kwsong           ###   ########.fr       */
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
	this->inventory = other.inventory;
}

void MateriaSource::learnMateria(AMateria* m)
{
	inventory.AddItem(m);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < inventory.GetSize(); ++i)
	{
		if (type == inventory.GetSlot(i)->getType())
			return (inventory.GetSlot(i)->clone());
	}
	return NULL;
}