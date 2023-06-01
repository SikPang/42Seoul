/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:03:26 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/01 01:38:09 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double> BitcoinExchange::exchangeRates;

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	(void)other;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	(void)other;
	return *this;
}

void BitcoinExchange::setRates(std::ifstream& file)
{
	std::string line;

	while (!file.eof())
	{
		getline(file, line);
		std::string::size_type idx = line.find(',');

		std::string key = line.substr(0, idx);

		std::istringstream iss(line.substr(idx + 1, line.length() - (idx + 1)));
		double value;
		iss >> value;

		exchangeRates.insert(std::make_pair(key, value));
	}
}

bool checkValidValue(const std::string& valueStr)
{
	// 문자 있는지 파싱
	// int인지 double인지 확인 후 ㄱㄱ

	std::istringstream iss(valueStr);
	int value;
	
	iss >> value;
	if (iss.fail())
	{
		std::cout << "Error: too large a number.\n";
		return false;
	}
	else if (value < 0)
	{
		std::cout << "Error: not a positive number.\n";
		return false;
	}
}

bool checkValidData(const std::string& date)
{
	int cnt = 0;
	std::string::size_type idx = 0;
	std::string copy(date);
	
	while (cnt < 3)
	{
		idx = copy.find("-");
		if (cnt != 2 && idx == std::string::npos)
			break;

		std::string numStr;
		
		if (cnt != 2)
			numStr = copy.substr(0, idx);
		else
			numStr = copy;
		
		std::istringstream iss(numStr);
		int num;

		iss >> num;
		if (iss.fail())
		{
			std::cout << "Error: too large a number.\n";
			return false;
		}

		if ((cnt == 0 && (num < 0 || num > 9999))
			|| (cnt == 1 && (num < 1 || num > 12))
			|| (cnt == 2 && (num < 1 || num > 31)))
			break;
		
		copy = copy.substr(idx + 1, copy.length() - (idx + 1));
		++cnt;
	}
	
	if (cnt != 3)
	{
		std::cout << "Error: bad input => " << date << "\n";
		return false;
	}
	return true;
}

void BitcoinExchange::parseInput(std::ifstream& file)
{
	std::string line;

	while (!file.eof())
	{
		getline(file, line);
		
		std::string::size_type idx = line.find('|');
		std::string::size_type ridx = line.rfind('|');

		if (idx == std::string::npos
			|| idx != ridx
			|| (idx > 0 && line[idx - 1] != ' ')
			|| (idx < line.length() && line[idx + 1] != ' '))
		{
			std::cout << "Error: bad input => " << line << "\n";
			continue;;
		}

		std::string key = line.substr(0, idx - 1);
		if (!checkValidData(key))
			continue;

		std::string value = line.substr(idx + 1, line.length() - (idx + 1));
		if (!checkValidValue(value))
			continue;

		
	}
}