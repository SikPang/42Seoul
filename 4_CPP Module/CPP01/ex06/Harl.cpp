/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:38:28 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 14:17:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n";
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n\n";
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level)
{
	Pair pairs[NUM_LEVEL] = {Pair("DEBUG", HarlLevel::DEBUG), Pair("INFO", HarlLevel::INFO),
		Pair("WARNING", HarlLevel::WARNING), Pair("ERROR", HarlLevel::ERROR)};
	
	HarlLevel::NUM curLevel = HarlLevel::WRONG;
	
	for (int i = 0; i < NUM_LEVEL; ++i)
	{
		if (level == pairs[i].key)
		{
			curLevel = pairs[i].value;
			break;
		}
	}

	switch (curLevel)
	{
	case HarlLevel::DEBUG:
		debug();
	case HarlLevel::INFO:
		info();
	case HarlLevel::WARNING:
		warning();
	case HarlLevel::ERROR:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
}

// --- Pair
Harl::Pair::Pair(std::string key, HarlLevel::NUM value)
{
	this->key = key;
	this->value = value;
}

Harl::Pair::Pair(const Pair& pair)
{
	this->key = pair.key;
	this->value = pair.value;
}