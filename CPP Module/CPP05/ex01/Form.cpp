/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:08 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/17 16:25:40 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

Form::Form()
:	name("someForm"),
	isSigned(false),
	gradeForSign(75),
	gradeForExe(75)
{
	std::cout << "Form Created.\n";
}

Form::Form(std::string name, bool isSigned, int gradeForSign, int gradeForExe)
:	name(name),
	isSigned(isSigned),
	gradeForSign(gradeForSign),
	gradeForExe(gradeForExe)
{
	if (gradeForSign > 150 || gradeForExe > 150)
	{
		throw GradeTooLowException();
		return;
	}
	else if (gradeForSign < 1 || gradeForExe < 1)
	{
		throw GradeTooHighException();
		return;
	}
	std::cout << "Form Created.\n";
}

Form::Form(Form& instance)
:	name(instance.name),
	isSigned(instance.isSigned),
	gradeForSign(instance.gradeForSign),
	gradeForExe(instance.gradeForExe)
{
	std::cout << "Form Created.\n";
}

Form& Form::operator=(Form& instance)
{
	isSigned = instance.isSigned;
	
	return *this;
}

void Form::operator<<(Form& instance)
{
	std::cout << "Form: " << instance.getName() << ", isSigned: " << instance.getIsSiged()
		<< ", Form gradeForSign: " << instance.getGradeForSign()
		<< ", Form gradeForExe: " << instance.getGradeForExe() << "\n";
}

Form::~Form() 
{
	std::cout << "Form Destroyed.\n";
}

std::string Form::getName()
{
	return name;
}

bool Form::getIsSiged()
{
	return isSigned;
}

int Form::getGradeForSign()
{
	return gradeForSign;
}

int Form::getGradeForExe()
{
	return gradeForExe;
}

void Form::beSigned(Bureaucrat& bure)
{
	if (bure.getGrade() >= gradeForSign)
	{
		isSigned = true;
		std::cout << bure.getName() << " signed " << name << "\n";
	}
	else
	{
		std::cout << bure.getName() << " couldn’t sign " << name
			<< " because grade is too low to sign \n";
		throw Form::GradeTooLowException();
	}
}

// ----- inner class -----

void Form::GradeTooHighException::report()
{
	std::cerr << "grade is too high\n";
}

void Form::GradeTooLowException::report()
{
	std::cerr << "grade is too low\n";
}