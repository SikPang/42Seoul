/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/17 16:21:16 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
이제 관료들이 생겼으니, 그들에게 할 일을 좀 주자. 
서류 더미를 작성하는 것보다 더 좋은 활동이 있을까요?
그럼 폼 클래스를 만들어 봅시다. 다음이 있습니다:
• 상수 이름.
• 부호가 있는지 여부를 나타내는 부울입니다(건설 시에는 부호가 아님).
• 서명하려면 일정한 등급이 필요합니다.
• 그리고 그것을 실행하기 위해서는 일정한 등급이 필요하다.
이러한 모든 속성은 비공개이며 보호되지 않습니다.

양식의 등급은 관료에게 적용되는 동일한 규칙을 따릅니다. 
따라서 양식 그레이드가 범위를 벗어나는 경우 다음 예외가 발생합니다:
양식::GradeTooHighException 및 양식::GradeTooLowException.
이전과 마찬가지로, 모든 속성에 대한 쓰기 도구와 
모든 양식 정보를 인쇄하는 삽입(삽입) 연산자의 오버로드입니다.

또한 관료를 매개 변수로 사용하는 양식에 beSigned() 멤버 함수를 추가합니다.
 관료의 등급이 충분히 높을 경우(필요한 등급보다 높거나 동등할 경우) 
 양식 상태를 서명으로 변경합니다. 1등급이 2등급보다 높다는 것을 기억하세요.
등급이 너무 낮으면 던집니다 양식::GradeTooLowException
마지막으로, 기호 Form() 멤버 함수를 관료기구에 추가합니다. 
양식이 서명된 경우 다음과 같은 내용이 인쇄됩니다:
<bureaucrat> signed <form>

그렇지 않으면 다음과 같은 내용이 인쇄됩니다:
<bureaucrat> couldn’t sign <form> because <reason>
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