/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:05:48 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 16:47:44 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>

class ClapTrap
{
protected:
	std::string	name;
	int			hitPoint;
	int			energyPoint;
	int			attackDamage;
	std::string	species;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap& instance);
	~ClapTrap();
	ClapTrap&	operator=(ClapTrap& instance);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	int			getAttackDamage();
};

#endif