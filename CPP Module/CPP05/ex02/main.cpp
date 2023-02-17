/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/17 16:30:06 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
이제 기본적인 형태를 갖추었으므로, 실제로 무언가를 할 수 있는 몇 가지를 더 만들어야 할 때입니다.
모든 경우에 기본 클래스 양식은 추상 클래스여야 하므로 다음과 같아야 합니다
양식의 이름을 바꿉니다. 양식의 속성은 비공개로 유지되어야 하며 기본 클래스에 있어야 합니다.
다음 콘크리트 클래스를 추가합니다:
• 관목숲 조성 양식: 필수 등급: 부호 145, 실행 137
작업 디렉터리에 파일 <target>_shrubbery를 생성하고 그 안에 ASCII 트리를 작성합니다.
• Robotomy Request Form: 필수 등급: 부호 72, exec 45 드릴링 소음을 발생시킵니다. 그런 다음, <대상>이 로봇화되었음을 알립니다
성공적으로 50%의 시간을 보냈습니다. 그렇지 않으면 로봇 제거가 실패했음을 알립니다.
• 대통령 사면 양식: 필수 등급: 서명 25, exec 5 자포드 비블브록스에 의해 <대상>이 사면되었음을 알립니다.
이들은 모두 생성자에서 하나의 매개 변수, 즉 양식의 대상만 사용합니다. 예를 들어, 집에 관목을 심고 싶다면 "집"을 선택하세요.

이제 execute (Bureaucrat const & executor) const member 함수를 기본 폼에 추가하고 콘크리트 클래스의 폼 동작을 실행하는 함수를 구현합니다. 양식에 서명이 되어 있는지, 양식을 실행하려는 관료의 등급이 충분히 높은지 확인해야 합니다. 그렇지 않으면 해당 예외를 적용합니다.
모든 구체적인 클래스에서 요구 사항을 확인할지 아니면 기본 클래스에서 요구 사항을 확인할지(양식을 실행하기 위해 다른 함수를 호출할지)는 사용자에게 달려 있습니다. 하지만, 한 가지 방법이 다른 방법보다 더 예뻐요.
마지막으로 executeForm(Form const & Form) 멤버 기능을 Officerat에 추가합니다. 양식을 실행하려고 시도해야 합니다. 성공한 경우 다음과 같은 내용을 인쇄합니다:
실행된 <form>
그렇지 않으면 명시적 오류 메시지를 인쇄합니다.
*/

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	b1;
	Bureaucrat	b2("kim", 1);
	Bureaucrat	b3("lee", 150);
	Form		f1;
	Form		f2("form2", false, 80, 80);
	Form		f3("form3", false, 150, 150);
	
	b1 << b1;
	b2 << b2;
	b3 << b3;
	f1 << f1;
	f2 << f2;
	f3 << f3;

	try
	{
		f1.beSigned(b1);
	}
	catch(Form::GradeTooLowException& e)
	{
		e.report();
	}

	try
	{
		f1.beSigned(b2);
	}
	catch(Form::GradeTooLowException& e)
	{
		e.report();
	}

	try
	{
		f1.beSigned(b3);
	}
	catch(Form::GradeTooLowException& e)
	{
		e.report();
	}

	// ------------------------------------

	try
	{
		f2.beSigned(b1);
	}
	catch(Form::GradeTooLowException& e)
	{
		e.report();
	}

	try
	{
		f2.beSigned(b2);
	}
	catch(Form::GradeTooLowException& e)
	{
		e.report();
	}

	try
	{
		f2.beSigned(b3);
	}
	catch(Form::GradeTooLowException& e)
	{
		e.report();
	}

	// ------------------------------------

	try
	{
		f3.beSigned(b1);
	}
	catch(Form::GradeTooLowException& e)
	{
		e.report();
	}

	try
	{
		f3.beSigned(b2);
	}
	catch(Form::GradeTooLowException& e)
	{
		e.report();
	}

	try
	{
		f3.beSigned(b3);
	}
	catch(Form::GradeTooLowException& e)
	{
		e.report();
	}

	return 0;
}