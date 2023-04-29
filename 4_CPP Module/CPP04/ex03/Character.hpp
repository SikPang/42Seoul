/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:09:03 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/30 08:36:38 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "ICharacter.hpp"
#include "Inventory.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	Inventory inventory;

public:
	Character();
	Character(std::string name);
	Character(const Character& other);
	~Character();
	Character& operator=(const Character& other);

public:
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};