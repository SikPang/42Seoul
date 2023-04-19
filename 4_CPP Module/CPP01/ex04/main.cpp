/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:15:38 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/19 13:27:17 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "StringReplacer.hpp"

#include <stdio.h>

int main(int ac, char** av)
{
	if (ac != 4)
	{
		std::cout << "must need 3 arguments. [fileName] [targetString] [destString] (without [])\n";
		return 0;
	}

	StringReplacer sr(av[1], av[2], av[3]);
	
	if (sr.Replace() == false)
	{
		std::cout << "invalid fileName\n";
		return 1;
	}
}