/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 20:36:50 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "iter.hpp"

/*
3개의 매개 변수를 사용하고 아무것도 반환하지 않는 함수 템플릿 반복기를 구현.
• 첫 번째 매개 변수는 배열의 주소입니다.
• 두 번째는 배열의 길이입니다.
• 세 번째는 배열의 모든 요소에서 호출될 함수입니다.
테스트가 포함된 main.cpp 파일을 제출합니다. 
테스트 실행 파일을 생성하기에 충분한 코드를 제공하십시오.
이터 함수 템플릿은 모든 유형의 배열과 함께 작동해야 합니다. 
제3 파라미터는 인스턴스화된 함수 템플릿일 수 있다.
*/

#define ARR_SIZE 10

int main()
{
	std::string	sArr[ARR_SIZE];
	int			iArr[ARR_SIZE];
	float		fArr[ARR_SIZE];
	char		cArr[ARR_SIZE];
	long long	lArr[ARR_SIZE];

	iter(sArr, ARR_SIZE, temp);
	iter(iArr, ARR_SIZE, temp);
	iter(fArr, ARR_SIZE, temp);
	iter(cArr, ARR_SIZE, temp);
	iter(lArr, ARR_SIZE, temp);
	
	return 0;
}