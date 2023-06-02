/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:09:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/31 21:51:43 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
다음과 같은 제약 조건을 가진 프로그램을 만들어야 합니다:
• 프로그램 이름은 RPN입니다.
• 프로그램은 반전된 폴란드 수학식을 인수로 사용해야 합니다.
• 이 작업에 사용되고 인수로 전달되는 숫자는 항상 10보다 작습니다. 계산 자체뿐만 아니라 결과도 이 규칙을 고려하지 않습니다.
• 프로그램에서 이 식을 처리하고 표준 출력에 올바른 결과를 출력해야 합니다.
• 프로그램 실행 중 오류가 발생하면 표준 출력에 오류 메시지가 표시되어야 합니다.
• 프로그램이 "+ - / *" 토큰으로 작업을 처리할 수 있어야 합니다.
괄호나 십진수는 관리할 필요가 없습니다.
*/

#include <iostream>
#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Error\n";
		return 1;
	}

	RPN& rpn = RPN::getInstance();

	rpn.calculate(av[1]);
}