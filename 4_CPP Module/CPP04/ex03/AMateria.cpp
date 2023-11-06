/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:51:46 by kwsong            #+#    #+#             */
/*   Updated: 2023/11/06 21:03:53 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
	: type("")
{
}

AMateria::AMateria(std::string const & type)
	: type(type)
{
}

AMateria::AMateria(const AMateria& other)
	: type(other.type)
{
}

AMateria::~AMateria()
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
	type = other.type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* some Materia bolt to " << target.getName() << " *\n";
}