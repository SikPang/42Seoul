/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:01:10 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 18:37:43 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
모든 연습에 대해, 당신은 당신이 할 수 있는 가장 완벽한 테스트를 제공해야 한다.
각 클래스의 생성자 및 소멸자는 특정 메시지를 표시해야 합니다.
모든 클래스에 동일한 메시지를 사용하지 마십시오.
Animal이라는 간단한 기본 클래스를 구현하는 것부터 시작합니다.
보호된 속성은 다음과 같습니다:
• std:: 문자열 유형;

Animal에서 상속되는 Dog 클래스를 구현합니다.
Animal에서 상속되는 Cat 클래스를 구현합니다.
이 두 개의 파생 클래스는 이름에 따라 유형 필드를 설정해야 합니다.
그런 다음 Dog's type이 'Dog'로 초기화되고, Cat's type이 'Cat'로 초기화됩니다.
동물 클래스의 유형은 비워 두거나 선택한 값으로 설정할 수 있습니다.
모든 동물은 멤버 기능을 사용할 수 있어야 합니다: makeSound()
적절한 소리를 출력합니다(고양이는 짖지 않습니다).

이 코드를 실행하면 Dog와 Cat 클래스의 특정 소리를 출력해야 합니다
동물의 집.

작동 방식을 이해하려면 WrongAnimal 클래스에서 상속하는 WrongCat 클래스를 구현하십시오.
위의 코드에서 동물과 고양이를 잘못된 것으로 바꾸면 WrongCat이 Wrong Animal 사운드를 출력해야 합니다.
위에 제시된 테스트보다 더 많은 테스트를 구현하고 제출하십시오.
*/

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	
	return 0;
}