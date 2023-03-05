/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:35:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/17 17:48:25 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
unintptr_t serialize(Data* ptr);
포인터를 가져와서 부호 없는 정수형 uintptr_t로 변환한다.

데이터* 역직렬화(uintptr_traw);
부호 없는 정수 매개 변수를 가져와 데이터 포인터로 변환합니다.

비어 있지 않은(데이터 멤버가 있음을 의미함) 데이터 구조를 만들어야 합니다.
데이터 개체의 주소에서 serialize()를 사용하고 반환 값을 전달하여 deserialize()를 해제합니다.
그런 다음 deserialize()의 반환 값이 원래 포인터와 동일한지 확인합니다.
데이터 구조의 파일을 제출하는 것을 잊지 마십시오
*/

#include <iostream>
#include <string>
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main(int ac, char **av)
{
	Data*		data = new Data();
	uintptr_t	uLong = 42;

	Data*		s_data = deserialize(uLong);
	uintptr_t	s_uLong = serialize(data);

	Data*		f_data = deserialize(s_uLong);
	uintptr_t	f_uLong = serialize(s_data);

	std::cout << "before : " << data << "\n";
	std::cout << "before : " << uLong << "\n\n";

	std::cout << "casted : " << s_data << "\n";
	std::cout << "casted : " << s_uLong << "\n\n";

	std::cout << "after  : " << f_data << "\n";
	std::cout << "after  : " << f_uLong << "\n";
}