/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/17 15:23:09 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
사무실, 복도, 양식 및 대기열의 인공적인 악몽을 설계해 봅시다.
재미있겠어요? 아닌가요? 아쉽네요.
먼저, 이 거대한 관료기구의 가장 작은 톱니바퀴부터 시작하세요: 관료기구입니다.
관료는 다음을 갖추어야 한다:
• 상수 이름.
• 그리고 1등급(최상위 등급)에서 150등급(최하위 등급)까지의 등급입니다.
잘못된 등급을 사용하여 관료를 인스턴스화하려는 시도는 예외를 발생시켜야 합니다:
Bureaucrat::GradeTooHighException 또는
Bureautocrat::GradeTooLowException

getName()과 getGrade()의 두 가지 특성에 대한 getter를 제공합니다. 
또한 관료 등급을 증가시키거나 감소시키는 두 개의 구성원 기능을 
구현합니다. 등급이 범위를 벗어나는 경우 두 등급 모두 생성자와 
동일한 예외를 발생시킵니다.

기억하세요. 1등급이 가장 높고 150등급이 가장 낮기 때문에,
3등급을 올리는 것은 관료에게 2등급을 주어야 한다.

던져진 예외는 시도 및 캐치 블록을 사용하여 캐치할 수 있어야 합니다:

try
{
	관료들과 함께 무언가를 한다 
}
catch(메모::메모 & e)
{
	예외 처리 
}

삽입(θ) 연산자의 과부하를 구현하여 (각 괄호 없이) 
다음과 같은 것을 인쇄합니다:
<name>, bureaucrat grade <grade>.
*/

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1;
	b1 << b1;

	Bureaucrat b2("kim", 1);
	b2 << b2;
	
	Bureaucrat b3("lee", 150);
	b3 << b3;
	
	try
	{
		Bureaucrat b4("park", 0);
		b4 << b4;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		e.report();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		e.report();
	}
	
	try
	{
		Bureaucrat b5("song", 151);
		b5 << b5;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		e.report();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		e.report();
	}

	try
	{
		b2.upGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		e.report();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		e.report();
	}

	try
	{
		b3.downGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		e.report();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		e.report();
	}

	return 0;
}