/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:39:35 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/14 22:44:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	name = "";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie(Zombie& instance)
{
	name = instance.name;
}

Zombie& Zombie::operator=(Zombie& instance)
{
	name = instance.name;
}

Zombie::~Zombie()
{
	
}