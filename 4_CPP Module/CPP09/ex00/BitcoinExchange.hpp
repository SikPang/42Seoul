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
#include <algorithm>

namespace Type
{
	enum TYPE
	{
		NONE,
		INT,
		FLOAT,
		DOUBLE
	};
}

namespace Sign
{
	enum SIGN
	{
		NONE,
		MINUS,
		PLUS
	};
}

class BitcoinExchange
{
private:
	private:
	struct Num
	{
		Type::TYPE id;
		Sign::SIGN sign;
		union
		{
			int i;
			float f;
			double d;
		};
	};

private:
	static std::map<std::string, double> exchangeRates;
	static Num idNum;

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& other);

private:
	static void identify(const std::string& valueStr);
	static bool checkValidValue(const std::string& valueStr);
	static bool checkValidDate(const std::string& date);
	static bool errorReturn(const std::string& msg);
	template <typename T> static bool getNum(T& num, const std::string& str);
	static void print(const std::string& key, std::map<std::string, double>::iterator& curIter);

public:
	static void setRates(std::ifstream& file);
	static void parseInput(std::ifstream& file);
};

template <typename T>
bool BitcoinExchange::getNum(T& num, const std::string& str)
{
	std::istringstream iss(str);
	iss >> num;

	if (iss.fail())
		return errorReturn("too large a number.");
	else if (num < 0)
		return errorReturn("not a positive number.");
	return true;
}