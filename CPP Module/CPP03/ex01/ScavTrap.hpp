/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:10:08 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 16:46:26 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool	isAlive;
	bool	isGateKeeperMode;

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap& instance);
	~ScavTrap();
	ScavTrap&	operator=(ScavTrap& instance);

	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		guardGate();
	bool		IsAlive();
};

#endif