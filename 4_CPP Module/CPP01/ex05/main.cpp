/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:34:46 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/18 17:12:16 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "must need 1 argument\n";
		return 0;
	}

	Harl harl;

	harl.complain(av[1]);
}