/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:39:37 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/14 22:43:29 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>

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

	void	announce();
	void	die();
	void	setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

namespace HordeNum
{
	enum Horde
	{
		FIRST = 3,
		SECOND = 5,
		THIRD = 7
	};
}

#endif