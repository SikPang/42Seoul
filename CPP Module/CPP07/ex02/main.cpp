/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 21:10:28 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

/*
T형 요소를 포함하고 다음 동작 및 기능을 구현하는 클래스 템플릿 배열을 개발합니다:

• 매개 변수가 없는 생성: 빈 배열을 만듭니다.
• 부호 없는 intn을 매개 변수로 사용하는 생성: 
	기본적으로 초기화된 n개 요소의 배열을 만듭니다.
	팁: int * a = new int() 컴파일을 시도한 다음 *a를 표시합니다.
• 복사 및 할당 연산자에 의한 생성. 두 경우 모두 복사 후 
	원본 배열 또는 복사본을 수정하면 다른 배열에 영향을 미치지 않습니다.
• 메모리를 할당하려면 new[] 연산자를 사용해야 합니다. 
	예방적 할당(사전 메모리 할당)은 금지되어 있습니다. 
	할당되지 않은 메모리에 프로그램이 액세스하면 안 됩니다.
• 요소는 첨자 연산자 [ ]를 통해 액세스할 수 있습니다.
• [ ] 연산자를 사용하여 요소에 액세스할 때 인덱스가 범위를 벗어나면 
	std:: 예외가 느려집니다.
• 배열의 요소 수를 반환하는 멤버 함수 크기()입니다. 
	이 멤버 함수는 매개 변수를 사용하지 않으며 현재 인스턴스를 수정할 수 없습니다.

평소와 같이 모든 것이 예상대로 작동하는지 확인하고 테스트가 포함된 main.cpp 파일을 제출하십시오.
*/

#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	Array<int>			iArr1;
	Array<int>			iArr2(10);
	Array<float>		fArr(10);
	Array<char>			cArr(10);
	Array<std::string>	sArr(10);

	std::cout << "iArr1\n";
	for (int i=0; i<iArr1.Size(); ++i)
		std::cout << i << ":" << iArr1[i] << ", ";
	std::cout << "\n\n";

	std::cout << "iArr2\n";
	for (int i=0; i<iArr2.Size(); ++i)
		std::cout << i << ":" << iArr2[i] << ", ";
	std::cout << "\n\n";

	std::cout << "fArr\n";
	for (int i=0; i<fArr.Size(); ++i)
		std::cout << i << ":" << fArr[i] << ' ';
	std::cout << "\n\n";

	std::cout << "cArr\n";
	for (int i=0; i<cArr.Size(); ++i)
		std::cout << i << ":" << cArr[i] << ' ';
	std::cout << "\n\n";

	std::cout << "sArr\n";
	for (int i=0; i<sArr.Size(); ++i)
		std::cout << i << ":" << sArr[i] << ' ';
	std::cout << "\n\n";
	
	return 0;
}