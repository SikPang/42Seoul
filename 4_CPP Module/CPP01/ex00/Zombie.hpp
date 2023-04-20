/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:39:37 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 13:44:24 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"

class Zombie
{
private:
	std::string	name;

public:
	Zombie();
	Zombie(std::string name);
	Zombie(Zombie& instance);
	~Zombie();
	Zombie&	operator=(Zombie& instance);

public:
	void	announce();
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif