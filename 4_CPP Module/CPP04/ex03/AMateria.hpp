/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:49:24 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/29 20:03:41 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class ICharacter;

class AMateria
{
protected:
	std::string type;
	AMateria();

public:
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	virtual ~AMateria();
	AMateria& operator=(const AMateria& other);

public:
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};