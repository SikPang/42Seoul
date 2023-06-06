/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:09:52 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/06 21:08:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
다음과 같은 제약 조건을 가진 프로그램을 만들어야 합니다:
• 그 프로그램의 이름은 PmergeMe입니다.
• 프로그램에서 양의 정수 시퀀스를 인수로 사용할 수 있어야 합니다.
• 프로그램에서 양의 정수 시퀀스를 정렬하려면 병합-삽입 정렬 알고리즘을 사용해야 합니다.
• 프로그램 실행 중 오류가 발생하면 표준 출력에 오류 메시지가 표시되어야 합니다.

이 연습의 유효성을 검사하려면 코드에 적어도 두 개의 서로 다른 컨테이너를 사용해야 합니다. 
프로그램에서 최소 3000개의 다른 정수를 처리할 수 있어야 합니다.
각 컨테이너에 대해 알고리즘을 구현하여 일반 함수를 사용하지 않는 것이 좋습니다.

다음은 표준 출력에 한 줄씩 표시해야 하는 정보에 대한 몇 가지 추가 지침입니다
• 첫 번째 줄에는 명시적 텍스트와 정렬되지 않은 양의 정수 시퀀스를 표시해야 합니다.
• 두 번째 줄에는 명시적 텍스트와 정렬된 양의 정수 시퀀스를 표시해야 합니다.
• 세 번째 줄에는 양의 정수 시퀀스를 정렬하는 데 사용되는 첫 번째 컨테이너를 지정하여 
	알고리즘에 사용된 시간을 나타내는 명시적 텍스트를 표시해야 합니다.
• 마지막 줄에 양의 정수 시퀀스를 정렬하는 데 사용되는 두 번째 컨테이너를 지정하여 
	알고리즘에 사용된 시간을 나타내는 명시적 텍스트를 표시해야 합니다.
정렬을 수행하는 데 사용된 시간의 표시 형식은 무료이지만
선택한 정밀도를 통해 사용된 두 용기 간의 차이를 명확하게 확인할 수 있어야 합니다.

이 예에서는 시간 표시가 의도적으로 이상합니다.
물론 정렬 부분과 데이터 관리 부분 모두에서 모든 작업을 수행하는 데 사용되는 시간을 표시해야 합니다.

중복과 관련된 오류의 관리는 귀하의 재량에 맡깁니다.
*/

// vector, deque

#include "PmergeMe.hpp"
#include <ctime>
#include <climits>

// sysconf(_SC_CLK_TCK);
unsigned long long ticksToMicroseconds(clock_t ticks) {
	std::cout << ticks << "\n";
    static double microsecondsPerTick = 1.0 / CLOCKS_PER_SEC * 1000000.0;
    return static_cast<unsigned long long>(ticks * microsecondsPerTick);
}

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cout << "Error\n";
		return 1;
	}
	
	PmergeMe& p = PmergeMe::getInstance();

	clock_t begin = clock();
	try
	{
		p.setArgs(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
		return 1;
	}
	p.sort();
	clock_t end = clock();

	unsigned long long elapsedMicroseconds = ticksToMicroseconds(end - begin);
    std::cout <<  elapsedMicroseconds <<  std::endl;
	
	return 0;
}