/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:03:24 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/01 00:48:46 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class BitcoinExchange
{
private:
	static std::map<std::string, double> exchangeRates;

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& other);

public:
	static void setRates(std::ifstream& file);
	static void parseInput(std::ifstream& file);
};

bool checkValidData(const std::string& date);