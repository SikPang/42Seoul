/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:15:38 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/18 19:56:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
파일 이름과 두 문자열 s1과 s2의 순서로 세 개의 매개 변수를 사용하는 프로그램을 만듭니다.
파일 이름을 열고 내용을 새 파일 이름으로 복사하여 s1의 모든 항목을 s2로 대체합니다.

C 파일 조작 기능을 사용하는 것은 금지되며 부정행위로 간주될 것이다. 
std::string 클래스의 모든 멤버 함수가 허용됩니다 (str::string::replace 제외). 
그것들을 현명하게 사용하세요!

물론 예상치 못한 입력과 오류를 처리해야 합니다.
프로그램이 예상대로 작동하는지 확인하려면 자체 테스트를 만들고 제출해야 합니다.
*/

#include <iostream>
#include <string>
#include "StringReplacer.hpp"

void MyReplace(std::string line, std::string targetString, std::string destString)
{
	
}

int main(int ac, char** av)
{
	if (ac != 4)
	{
		std::cout << "must need 3 arguments. [fileName] [targetString] [destString] (without [])\n";
		return 0;
	}

	StringReplacer sr(av[1], av[2], av[3]);

	if (targetFile.fail())
	{
		std::cout << "invalid fileName\n";
		return 0;
	}

	while (!targetFile.eof())
	{
		std::string	line;

		getline(targetFile, line);

		for (int i = 0; i < line.size(); ++i)
		{
			
		}
	}
}