/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:09:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/09 14:07:10 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "BitcoinExchange.hpp"

// void v()
// {
// 	system("leaks btc");
// }

int main(int ac, char** av)
{
	//atexit(v);
	if (ac != 2)
	{
		std::cout << "Error: could not open file.\n";
		return 1;
	}

	std::ifstream database("data.csv");
	std::ifstream input(av[1]);
	
	if (database.fail() || input.fail())
	{
		std::cout << "Error: could not open file.\n";
		return 1;
	}

	BitcoinExchange& be = BitcoinExchange::getInstance();
	be.setRates(database);
	be.parseInput(input);

	return 0;
}