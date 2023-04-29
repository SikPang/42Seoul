/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:00:07 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 20:04:24 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
	: AMateria("cure")
{
}

Cure::Cure(const Cure& other)
	: AMateria(other)
{
}

Cure::~Cure()
{
}

Cure& Cure::operator=(const Cure& other)
{
	type = other.type;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *";
}