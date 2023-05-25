/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:16:32 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/25 20:48:32 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>

namespace ID
{
	enum id
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		NONE
	};
}

namespace SIGN
{
	enum sign
	{
		PLUS,
		MINUS,
		NONE
	};
}

class ScalarConverter
{
private:
	struct Num
	{
		int id;
		int sign;
		union
		{
			char c;
			int i;
			float f;
			double d;
		};
	};
	static Num idNum;

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);

private:
	static bool toInt(const std::string& str);
	static bool toFloat(const std::string& str);
	static bool toDouble(const std::string& str);
	static void identify(const std::string& str);
	static void printNaN();
	static void print(const std::string& str, bool isOverflowed);

private:
	template <typename T>
	static void do_static_cast()
	{
		switch(idNum.id)
		{
			case ID::CHAR:
				std::cout << static_cast<T>(idNum.c);
				break;
			case ID::INT:
				std::cout << static_cast<T>(idNum.i);
				break;
			case ID::FLOAT:
				std::cout << static_cast<T>(idNum.f);
				break;
			case ID::DOUBLE:
				std::cout << static_cast<T>(idNum.d);
				break;
		}
	}

public:
	static void convert(const std::string& str);
};