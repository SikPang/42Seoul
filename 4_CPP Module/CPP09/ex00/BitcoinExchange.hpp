/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:03:24 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/09 16:30:04 by kwsong           ###   ########.fr       */
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
	std::map<std::string, double> exchangeRates;
	Num idNum;

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& other);

private:
	void identify(const std::string& valueStr);
	bool checkValidValue(const std::string& valueStr);
	bool checkValidDate(const std::string& date);
	template <typename T> bool getNum(T& num, const std::string& str);
	void print(const std::string& key, std::map<std::string, double>::iterator& curIter);

public:
	static BitcoinExchange& getInstance();
	void setRates(std::ifstream& file);
	void parseInput(std::ifstream& file);
};

template <typename T>
bool BitcoinExchange::getNum(T& num, const std::string& str)
{
	std::istringstream iss(str);
	iss >> num;

	if (iss.fail() || num >= 1000 || num >= 999.999)
	{
		std::cout << "Error: too large a number.\n";
		return false;
	}
	else if (num == 0)
	{
		std::cout << "Error: too small a number.\n";
		return false;
	}
	else if (num < 0)
	{
		std::cout << "Error: not a positive number.\n";
		return false;
	}
	return true;
}