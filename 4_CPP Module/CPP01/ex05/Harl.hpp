/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:38:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/18 19:46:35 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>

#define NUM_LEVEL 4

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
		void (Harl::*value)(void);
		
	public:
		Pair(std::string key, void (Harl::*value)(void));
		Pair(const Pair& pair);
	};

public:
	void complain(std::string level);
};

#endif