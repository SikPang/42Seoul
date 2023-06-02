/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:09:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/01 00:37:41 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
당신은 특정 날짜에 특정 비트코인의 가치를 출력하는 프로그램을 만들어야 합니다.
이 프로그램은 시간이 지남에 따라 비트코인 가격을 나타내는 csv 형식의 데이터베이스를 사용해야 합니다. 
이 데이터베이스는 이 제목과 함께 제공됩니다.
프로그램은 평가할 여러 가격/날짜를 저장하는 두 번째 데이터베이스를 입력합니다.
프로그램은 다음 규칙을 준수해야 합니다:
• 프로그램 이름은 btc입니다.
• 프로그램에서 파일을 인수로 사용해야 합니다.
• 이 파일의 각 행은 "날짜 | 값" 형식을 사용해야 합니다.
• 유효한 날짜는 항상 다음 형식입니다: 년-월-일.
• 유효한 값은 0에서 1000 사이의 부동소수 또는 양의 정수여야 합니다

프로그램에서 입력 파일의 값을 사용합니다.
프로그램은 데이터베이스에 표시된 날짜에 따라 값에 환율을 곱한 결과를 표준 출력에 표시해야 합니다.
입력에 사용된 날짜가 DB에 없는 경우 DB에 포함된 가장 가까운 날짜를 사용해야 합니다.
 위쪽 날짜가 아닌 아래쪽 날짜를 사용하도록 주의하십시오.
*/

// CRLF Check

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
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