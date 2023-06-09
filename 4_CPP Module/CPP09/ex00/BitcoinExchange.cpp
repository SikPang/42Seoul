/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:03:26 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/09 13:36:03 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
	: exchangeRates()
	, idNum()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: exchangeRates(other.exchangeRates)
	, idNum(other.idNum)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	exchangeRates = other.exchangeRates;
	idNum = other.idNum;
	return *this;
}

BitcoinExchange& BitcoinExchange::getInstance()
{
	static BitcoinExchange instance;
	return instance;
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

bool BitcoinExchange::errorReturn(const std::string& msg)
{
	std::cout << "Error: " << msg << "\n";
	return false;
}

void BitcoinExchange::identify(const std::string& valueStr)
{
	int floatIdx = -1;
	int pointIdx = -1;
	int i = 0;

	while (valueStr[i] == '-' || valueStr[i] == '+')
	{
		if (valueStr[i] == '-')
		{
			if (idNum.sign == Sign::NONE)
				idNum.sign = Sign::MINUS;
			else
			{ 
				idNum.id = Type::NONE; 
				return; 
			}
		}
		else if (valueStr[i] == '+')
		{
			if (idNum.sign == Sign::NONE)
				idNum.sign = Sign::PLUS;
			else
			{
				idNum.id = Type::NONE; 
				return;
			}
		}
		++i;
	}
	if (i == (int)valueStr.length())
	{
		idNum.id = Type::NONE;
		return;
	}

	for (; i < (int)valueStr.length() && valueStr[i] != 13 && valueStr[i] != 10; ++i)
	{
		if (valueStr[i] == 'f')
		{
			if (i != (int)valueStr.length() - 1 || floatIdx != -1)
			{ 
				idNum.id = Type::NONE;
				return;
			}
			else
				floatIdx = i;
		}
		else if (valueStr[i] == '.')
		{
			if (pointIdx == -1)
				pointIdx = i;
			else
			{ 
				idNum.id = Type::NONE;
				return;
			}
		}
		else if (valueStr[i] < '0' || valueStr[i] > '9')
		{ 
			idNum.id = Type::NONE;
			return;
		}
	}
		
	if (floatIdx != -1)
	{
		if (pointIdx == -1 || floatIdx < pointIdx || (floatIdx == 1 && pointIdx == 0))
		{
			idNum.id = Type::NONE; 
			return; 
		}
		else
			idNum.id = Type::FLOAT;
	}
	else if (pointIdx != -1)
		idNum.id = Type::DOUBLE;
	else
		idNum.id = Type::INT;
}

bool BitcoinExchange::checkValidValue(const std::string& valueStr)
{		
	if (valueStr == "value")
		return true;
	
	identify(valueStr);
	bool isValid = false;

	switch(idNum.id)
	{
	case Type::INT:
		isValid = getNum(idNum.i, valueStr);
		break;
	case Type::FLOAT:
		isValid = getNum(idNum.f, valueStr);
		break;
	case Type::DOUBLE:
		isValid = getNum(idNum.d, valueStr);
		break;
	default:
		std::cout << "Error: bad input => " << valueStr << "\n";
		break;
	}
	return isValid;
}

bool BitcoinExchange::checkValidDate(const std::string& date)
{
	if (date == "date")
		return true;

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

		for (int i = 0; i < (int)numStr.length(); ++i)
		{
			if (numStr[i] < '0' || numStr[i] > '9')
			{
				std::cout << "Error: bad input => " << date << "\n";
				return false;
			}
		}

		std::istringstream iss(numStr);
		int num;

		iss >> num;
		if (iss.fail())
			return errorReturn("too large a number.");

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

void BitcoinExchange::print(const std::string& key, std::map<std::string, double>::iterator& curIter)
{
	std::map<std::string, double>::iterator prevIter;

	while (true)
	{
		prevIter = curIter;
		for (; curIter != exchangeRates.end() && (*curIter).first <= key; ++curIter)
			prevIter = curIter;
		
		if ((*prevIter).first <= key)
			break;
		curIter = exchangeRates.begin();
	}
	
	//std::cout << "(" << (*prevIter).first << ", " << (*prevIter).second << ") ";
	std::cout << key << " => ";
	switch (idNum.id)
	{
	case Type::INT:
		std::cout << idNum.i << " = " << (*prevIter).second * idNum.i << "\n";
		break;
	case Type::FLOAT:
		std::cout << idNum.f << " = " << (*prevIter).second * idNum.f << "\n";
		break;
	default:
		std::cout << idNum.d << " = " << (*prevIter).second * idNum.d << "\n";
		break;
	}

	curIter = prevIter;
}

void BitcoinExchange::parseInput(std::ifstream& file)
{
	std::map<std::string, double>::iterator curIter = exchangeRates.begin();
	std::string line;

	while (!file.eof())
	{
		getline(file, line);
		idNum.id = Type::NONE;
		idNum.sign = Sign::NONE;
		std::string::size_type idx = line.find('|');
		std::string::size_type ridx = line.rfind('|');

		if (idx == std::string::npos
			|| idx != ridx
			|| (idx > 0 && line[idx - 1] != ' ')
			|| (idx < line.length() && line[idx + 1] != ' '))
		{
			std::cout << "Error: bad input => " << line << "\n";
			continue;
		}

		std::string key = line.substr(0, idx - 1);
		if (!checkValidDate(key))
			continue;

		std::string value = line.substr(idx + 2, line.length() - (idx + 2));
		std::string::const_iterator iter = find(value.begin(), value.end(), 13);
		if (iter != value.end())
			value.erase(value.length() - 1);
		if (!checkValidValue(value) || idNum.id == Type::NONE)
			continue;

		print(key, curIter);
	}
}