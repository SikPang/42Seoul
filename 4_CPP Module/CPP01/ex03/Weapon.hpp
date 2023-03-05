/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:00:22 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/15 18:10:27 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <string>

class Weapon
{
private:
	std::string	type;

public:
	Weapon();
	Weapon(std::string type);
	Weapon(Weapon& instance);
	~Weapon();
	Weapon&	operator=(Weapon& instance);

	const std::string&	getType();
	void				setType(std::string type);
};

#endif