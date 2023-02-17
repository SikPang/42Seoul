/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:08 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/17 16:24:07 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"

AForm::AForm()
:	name("someAForm"),
	isSigned(false),
	gradeForSign(75),
	gradeForExe(75)
{
	std::cout << "AForm Created.\n";
}

AForm::AForm(std::string name, bool isSigned, int gradeForSign, int gradeForExe)
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
	std::cout << "AForm Created.\n";
}

AForm::AForm(AForm& instance)
:	name(instance.name),
	isSigned(instance.isSigned),
	gradeForSign(instance.gradeForSign),
	gradeForExe(instance.gradeForExe)
{
	std::cout << "AForm Created.\n";
}

AForm& AForm::operator=(AForm& instance)
{
	isSigned = instance.isSigned;
	
	return *this;
}

void AForm::operator<<(AForm& instance)
{
	std::cout << "AForm: " << instance.getName() << ", isSigned: " << instance.getIsSiged()
		<< ", AForm gradeForSign: " << instance.getGradeForSign()
		<< ", AForm gradeForExe: " << instance.getGradeForExe() << "\n";
}

AForm::~AForm() 
{
	std::cout << "AForm Destroyed.\n";
}

std::string AForm::getName()
{
	return name;
}

bool AForm::getIsSiged()
{
	return isSigned;
}

int AForm::getGradeForSign()
{
	return gradeForSign;
}

int AForm::getGradeForExe()
{
	return gradeForExe;
}

void AForm::beSigned(Bureaucrat& bure)
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
		throw AForm::GradeTooLowException();
	}
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