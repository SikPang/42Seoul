/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:35:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/25 21:05:44 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
다음 방법을 사용하여 정적 클래스 직렬화 프로그램을 구현합니다:
uninttr_t serialize(Data* ptr);
포인터를 가져와 부호 없는 정수 유형 uinttr_t로 변환합니다.
데이터* 역직렬화(inttr_trraw);
부호 없는 정수 매개 변수를 사용하여 데이터 포인터로 변환합니다.
수업이 예상대로 작동하는지 테스트할 프로그램을 작성합니다.
비어 있지 않은 데이터 구조(데이터 구성원이 있음을 의미)를 만들어야 합니다.

Data 개체의 주소에 serialize()를 사용하고 반환 값을 전달하여 deserialize()를 수행합니다. 그런 다음 deserialize()의 반환 값이 원래 포인터와 동일한지 확인합니다.

데이터 구조의 파일을 제출하는 것을 잊지 마십시오.
*/

#include <iostream>
#include <string>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	uintptr_t uLong = 42;
	Data* data = new Data();
	data->data = "hello world";

	std::cout << "before : " << data->data << "\n";
	std::cout << "before : " << uLong << "\n\n";

	uintptr_t after_uLong = Serializer::serialize(Serializer::deserialize(uLong));
	Data* after_data = Serializer::deserialize(Serializer::serialize(data));

	std::cout << "after  : " << after_data->data << "\n";
	std::cout << "after  : " << after_uLong << "\n";

	delete data;
}