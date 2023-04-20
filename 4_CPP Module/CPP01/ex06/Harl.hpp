/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:38:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 14:16:25 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>

#define NUM_LEVEL 4

namespace HarlLevel
{
	enum NUM
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		WRONG
	};
}

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

private:
	struct Pair
	{
	public:
		std::string key;
		HarlLevel::NUM value;
		
	public:
		Pair(std::string key, HarlLevel::NUM value);
		Pair(const Pair& pair);
	};

public:
	void complain(std::string level);
};

#endif