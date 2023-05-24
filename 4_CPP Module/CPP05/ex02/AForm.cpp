/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:08 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/24 14:33:01 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: name("someAForm")
	, gradeForSign(75)
	, gradeForExe(75)
	, isSigned(false)
{
	std::cout << "AForm " << name << " Created.\n";
}

AForm::AForm(const std::string& name, int gradeForSign, int gradeForExe)
	: name(name)
	, gradeForSign(gradeForSign)
	, gradeForExe(gradeForExe)
	, isSigned(false)
{
	if (gradeForSign > GRADE_LIMIT_LOW || gradeForExe > GRADE_LIMIT_LOW)
		throw GradeTooLowException();
	else if (gradeForSign < GRADE_LIMIT_HIGH || gradeForExe < GRADE_LIMIT_HIGH)
		throw GradeTooHighException();
	
	std::cout << "AForm " << name << " Created.\n";
}

AForm::AForm(const AForm& instance)
	: name(instance.name)
	, gradeForSign(instance.gradeForSign)
	, gradeForExe(instance.gradeForExe)
	, isSigned(instance.isSigned)
{
	std::cout << "AForm " << name << " Created.\n";
}

AForm& AForm::operator=(const AForm& instance)
{
	isSigned = instance.isSigned;
	return *this;
}

AForm::~AForm() 
{
	std::cout << "AForm " << name << " Destroyed.\n";
}

const std::string& AForm::getName() const
{
	return name;
}

bool AForm::getIsSiged() const
{
	return isSigned;
}

int AForm::getGradeForSign() const
{
	return gradeForSign;
}

int AForm::getGradeForExe() const
{
	return gradeForExe;
}

void AForm::beSigned(const Bureaucrat& bure)
{
	if (isSigned)
		throw AForm::AlreadySigned();
	else if (bure.getGrade() <= gradeForSign)
		isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned)
		throw AForm::NotSigned();
	else if (executor.getGrade() > gradeForExe)
		throw AForm::GradeTooLowException();
}

// ----- inner class -----

void AForm::GradeTooHighException::report()
{
	std::cerr << "grade is too high\n";
}

void AForm::GradeTooLowException::report()
{
	std::cerr << "grade is too low\n";
}

void AForm::AlreadySigned::report()
{
	std::cerr << "already signed\n";
}

void AForm::NotSigned::report()
{
	std::cerr << "not signed\n";
}

// ----- extern -----

std::ostream& operator<<(std::ostream& os, const AForm& instance)
{
	std::cout << "AForm: " << instance.getName() << ", isSigned: " << instance.getIsSiged()
		<< ", AForm gradeForSign: " << instance.getGradeForSign()
		<< ", AForm gradeForExe: " << instance.getGradeForExe() << "\n";
	return (os);
}
