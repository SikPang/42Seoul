/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:01:22 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 17:21:24 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
박수 트랩을 만드는 것은 아마도 여러분의 신경을 건드리기 시작할 것입니다.
이제 ClapTrap에서 상속되는 FragTrap 클래스를 구현합니다.

그것은 ScavTrap과 매우 유사하다.
그러나, 그것의 건설과 파괴 메시지는 달라야 한다.
테스트에 적절한 구조/파괴 체인이 표시되어야 합니다.

FragTrap이 생성되면 프로그램은 ClapTrap을 빌드하는 것으로 시작합니다.
파괴는 역순이다.

속성도 동일하지만 이번에는 값이 다릅니다:
• 생성자에게 매개 변수로 전달되는 이름
• 적중점(100), ClapTrap의 상태를 나타냅니다
• 에너지 포인트(100)
• 공격 데미지(30)

FragTrap에는 특별한 용량도 있습니다:
void high Five guys(void);
이 멤버 함수는 표준 출력에 양의 하이파이브 요청을 표시한다.
다시 프로그램에 테스트를 추가합니다.
*/
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void PrevFunc()
{
	ClapTrap	ctA("A");
	ClapTrap	ctB("B");

	for (int i = 0; i < 10; ++i)
	{
		ctA.attack("B");
		ctB.takeDamage(ctA.getAttackDamage());
	}

	ctA.attack("B");
	ctA.beRepaired(1);
	
	ctB.beRepaired(1);
	ctB.beRepaired(1);
}

int main()
{
	PrevFunc();
	std::cout << "-----------------------------------\n";

	FragTrap ftA("A");
	FragTrap ftB("B");

	for (int i = 0; i < 5; ++i)
	{
		ftA.attack("B");
		ftB.takeDamage(ftA.getAttackDamage());
	}
	
	ftB.highFivesGuys();
	ftB.beRepaired(1);

	ftB.highFivesGuys();
	ftB.beRepaired(1);
}