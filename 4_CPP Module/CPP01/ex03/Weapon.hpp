/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:00:22 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 14:20:40 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <string>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"

class Weapon
{
private:
	std::string	type;

public:
	Weapon();
	Weapon(std::string type);
	Weapon(const Weapon& instance);
	~Weapon();
	Weapon&	operator=(Weapon& instance);

	const std::string&	getType();
	void				setType(std::string type);
};

#endif