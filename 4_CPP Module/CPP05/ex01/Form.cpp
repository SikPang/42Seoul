/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:08 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/24 14:32:49 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: name("someForm")
	, gradeForSign(75)
	, gradeForExe(75)
	, isSigned(false)
{
	std::cout << "Form " << name << " Created.\n";
}

Form::Form(const std::string& name, int gradeForSign, int gradeForExe)
	: name(name)
	, gradeForSign(gradeForSign)
	, gradeForExe(gradeForExe)
	, isSigned(false)
{
	if (gradeForSign > GRADE_LIMIT_LOW || gradeForExe > GRADE_LIMIT_LOW)
		throw GradeTooLowException();
	else if (gradeForSign < GRADE_LIMIT_HIGH || gradeForExe < GRADE_LIMIT_HIGH)
		throw GradeTooHighException();
	
	std::cout << "Form " << name << " Created.\n";
}

Form::Form(const Form& instance)
	: name(instance.name)
	, gradeForSign(instance.gradeForSign)
	, gradeForExe(instance.gradeForExe)
	, isSigned(instance.isSigned)
{
	std::cout << "Form " << name << " Created.\n";
}

Form& Form::operator=(const Form& instance)
{
	isSigned = instance.isSigned;
	return *this;
}

Form::~Form() 
{
	std::cout << "Form " << name << " Destroyed.\n";
}

const std::string& Form::getName() const
{
	return name;
}

bool Form::getIsSiged() const
{
	return isSigned;
}

int Form::getGradeForSign() const
{
	return gradeForSign;
}

int Form::getGradeForExe() const
{
	return gradeForExe;
}

void Form::beSigned(const Bureaucrat& bure)
{
	if (isSigned)
		throw Form::AlreadySigned();
	else if (bure.getGrade() <= gradeForSign)
		isSigned = true;
	else
		throw Form::GradeTooLowException();
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

void Form::AlreadySigned::report()
{
	std::cerr << "already signed\n";
}

// ----- extern -----

std::ostream& operator<<(std::ostream& os, const Form& instance)
{
	std::cout << "Form: " << instance.getName() << ", isSigned: " << instance.getIsSiged()
		<< ", Form gradeForSign: " << instance.getGradeForSign()
		<< ", Form gradeForExe: " << instance.getGradeForExe() << "\n";
	return (os);
}
