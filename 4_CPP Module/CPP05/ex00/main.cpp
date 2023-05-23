/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/23 16:10:31 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1;
	std::cout << b1;

	Bureaucrat b2("kim", 1);
	std::cout << b2;

	Bureaucrat b3("lee", 150);
	std::cout << b3;

	std::cout << "----- 예외 발견 케이스 -----\n";

	try
	{
		Bureaucrat b4("park", 0);
		std::cout << b4;
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
		std::cout << b5;
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

	std::cout << "----- 정상 케이스 -----\n";

	try
	{
		Bureaucrat b6("park", 1);
		std::cout << b6;
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
		Bureaucrat b7("song", 150);
		std::cout << b7;
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
		b1.downGrade();
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
		b1.upGrade();
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