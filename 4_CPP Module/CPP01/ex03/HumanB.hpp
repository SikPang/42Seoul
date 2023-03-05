/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:12:41 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/15 18:32:10 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon*		weapon;

public:
	HumanB();
	HumanB(std::string name);
	HumanB(HumanB& instance);
	~HumanB();
	HumanB&	operator=(HumanB& instance);

	void	attack();
	void	setWeapon(Weapon& weapon);
};

#endif