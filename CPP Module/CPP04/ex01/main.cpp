/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:01:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 19:37:21 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
각 클래스의 생성자 및 소멸자는 특정 메시지를 표시해야 합니다.
브레인 클래스를 구현합니다.
아이디어라고 불리는 100 std:: 문자열 배열을 포함한다.
이렇게 하면 Dog and Cat은 개인 Brain* 속성을 갖게 됩니다.
건설되면 개와 고양이는 새로운 뇌()를 사용하여 뇌를 만들 것이다;
개와 고양이는 파괴되면 뇌를 삭제합니다.
주 기능에서 동물 개체의 배열을 만들고 채웁니다.
그것의 절반은 Dog 객체가 될 것이고 나머지 절반은 Cat 객체가 될 것이다.
프로그램 실행이 끝나면 이 배열에 루프를 적용하고 모든 동물을 삭제합니다.
개와 고양이를 동물로 직접 삭제해야 합니다.
적절한 소멸자를 예상 순서대로 호출해야 합니다.

메모리 누수를 확인하는 것을 잊지 마세요.
개나 고양이의 복제품은 얕아서는 안 된다.
따라서 사본이 심층 사본인지 테스트해야 합니다!
위에 제시된 테스트보다 더 많은 테스트를 구현하고 제출하십시오.
*/

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define ANIMAL_NUM 10

int main()
{
	const Animal* animals[ANIMAL_NUM];

	for (int i=0; i<ANIMAL_NUM/2; ++i)
	{
		animals[i] = new Cat();
		std::cout << "\n";
	}
	
	for (int i=ANIMAL_NUM/2; i<ANIMAL_NUM; ++i)
	{
		animals[i] = new Cat();
		std::cout << "\n";
	}

	for (int i=0; i<ANIMAL_NUM; ++i)
	{
		std::cout << "\n";
	 	delete animals[i];
	}
	
	return 0;
}