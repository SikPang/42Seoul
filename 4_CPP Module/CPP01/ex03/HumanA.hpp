/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:12:41 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 14:19:52 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon*		weapon;

public:
	HumanA(std::string name, Weapon& weapon);
	HumanA(HumanA& instance);
	~HumanA();
	HumanA&	operator=(HumanA& instance);

	void	attack();
};

#endif