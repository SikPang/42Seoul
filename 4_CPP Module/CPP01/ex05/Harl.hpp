/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:38:31 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/18 18:10:42 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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