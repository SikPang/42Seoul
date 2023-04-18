/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:38:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/18 19:12:58 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#define NUM_LEVEL 4

enum HarlLevel
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

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
		HarlLevel value;
		
	public:
		Pair(std::string key, HarlLevel value);
		Pair(const Pair& pair);
	};

public:
	void complain(std::string level);
};