/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:16:34 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/26 14:22:12 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::Num ScalarConverter::idNum = {};

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

void ScalarConverter::printNaN()
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: nanf\n";
	std::cout << "double: nan\n";
}

void ScalarConverter::print(std::string& str, bool isOverflowed)
{
	std::string intStr(str);
	if (intStr[0] == '.')
		intStr.insert(intStr.begin(), '0');
	else if ((intStr[0] == '+' || intStr[0] == '-') && intStr[1] == '.')
		intStr.insert(intStr.begin() + 1, '0');

	std::istringstream issc(intStr);
	int c;
	issc >> c;
	if (issc.fail() || c < -128 || c > 127)
		std::cout << "char: overflowed\n";
	else if (!isprint(c))
		std::cout << "char: Non displayable" << "\n";
	else
	{
		std::cout << "char: '";
		do_static_cast<char>();
		std::cout << "'\n";
	}
	
	if ((idNum.id == ID::INT && isOverflowed) || issc.fail())
		std::cout << "int: overflowed\n";
	else if (isOverflowed)
		std::cout << "int: " << c << "\n";
	else
	{
		std::cout << "int: ";
		do_static_cast<int>();
		std::cout << "\n";
	}
	
	std::istringstream issf(str);
	float f;
	issf >> f;
	if ((idNum.id == ID::FLOAT && isOverflowed) || issf.fail())
		std::cout << "float: overflowed\n";
	else if (std::isinf(f))
	{
		if (idNum.sign == SIGN::MINUS)
			std::cout << "float: -inff\n";
		else
			std::cout << "float: +inff\n";
	}
	else
	{
		std::cout << "float: ";
		if (isOverflowed)
			std::cout << f;
		else
			do_static_cast<float>();
		
		if (f - static_cast<int>(f) == 0.f)
			std::cout << ".0f\n";
		else
			std::cout << "f\n";
	}

	std::istringstream issd(str);
	double d;
	issd >> d;
	if ((idNum.id == ID::DOUBLE && isOverflowed))
		std::cout << "double: overflowed\n";
	else if (std::isinf(d))
	{
		if (idNum.sign == SIGN::MINUS)
			std::cout << "double: -inf\n";
		else
			std::cout << "double: +inf\n";
	}
	else
	{
		std::cout << "double: ";
		if (isOverflowed)
			std::cout << d;
		else
			do_static_cast<double>();
		if (d - static_cast<int>(d) == 0.0)
			std::cout << ".0\n";
		else
			std::cout << "\n";
	}
}

bool ScalarConverter::toInt(const std::string& str)
{
	std::istringstream iss(str);
	int i;

	iss >> i;
	if (iss.fail())
		return true;
	else
		idNum.i = i;
	return false;
}

bool ScalarConverter::toFloat(const std::string& str)
{
	std::istringstream iss(str);
	float f;

	iss >> f;
	if (iss.fail())
		return true;
	else
		idNum.f = f;
	return false;
}

bool ScalarConverter::toDouble(const std::string& str)
{
	std::istringstream iss(str);
	double d;

	iss >> d;
	if (iss.fail())
		return true;
	else
		idNum.d = d;
	return false;
}

void ScalarConverter::identify(const std::string& str)
{
	int floatIdx = -1;
	int pointIdx = -1;
	int i = 0;
	idNum.sign = SIGN::NONE;

	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			if (idNum.sign == SIGN::NONE)
				idNum.sign = SIGN::MINUS;
			else
			{
				idNum.id = ID::NONE;
				return;
			}
		}
		else if (str[i] == '+')
		{
			if (idNum.sign == SIGN::NONE)
				idNum.sign = SIGN::PLUS;
			else
			{
				idNum.id = ID::NONE;
				return;
			}
		}
		++i;
	}
	if (i == (int)str.length())
	{
		idNum.id = ID::NONE;
		return;
	}

	for (; i < (int)str.length(); ++i)
	{
		if (str[i] == 'f')
		{
			if (i != (int)str.length() - 1 || floatIdx != -1)
			{
				idNum.id = ID::NONE;
				return;
			}
			else
				floatIdx = i;
		}
		else if (str[i] == '.')
		{
			if (pointIdx == -1)
				pointIdx = i;
			else
			{
				idNum.id = ID::NONE;
				return;
			}
		}
		else if (str[i] < '0' || str[i] > '9')
		{
			idNum.id = ID::NONE;
			return;
		}
	}
		
	if (floatIdx != -1)
	{
		if (pointIdx == -1 || floatIdx < pointIdx || (floatIdx == 1 && pointIdx == 0))
			idNum.id = ID::NONE;
		else
			idNum.id = ID::FLOAT;
	}
	else if (pointIdx != -1)
		idNum.id = ID::DOUBLE;
	else
		idNum.id = ID::INT;
}

void ScalarConverter::convert(const std::string& str)
{
	std::string new_str = const_cast<std::string&>(str);
	identify(new_str);

	bool isOverflowed = false;
	switch (idNum.id)
	{
	case ID::INT:
		isOverflowed = toInt(new_str);
		break;
	case ID::FLOAT:
		new_str = new_str.substr(0, str.length() - 1);
		isOverflowed = toFloat(new_str);
		break;
	case ID::DOUBLE:
		isOverflowed = toDouble(new_str);
		break;
	}

	if (idNum.id == ID::NONE)
		printNaN();
	else
		print(new_str, isOverflowed);
}