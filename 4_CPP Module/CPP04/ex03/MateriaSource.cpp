/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:49:03 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 20:25:21 by kwsong           ###   ########.fr       */
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

}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{

}

void MateriaSource::learnMateria(AMateria* m)
{
	
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type == "ice")
		return new Ice();
	else if (type == "cure")
		return new Cure();
	else
		return NULL;
}