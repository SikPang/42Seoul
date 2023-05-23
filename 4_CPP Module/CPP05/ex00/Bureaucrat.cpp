/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:18:28 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/23 19:21:04 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: name("someone")
	, grade(75)
{
	std::cout << "Bureaucrat Created.\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name(name)
	, grade(grade)
{
	if (grade > GRADE_LIMIT_LOW)
	{
		throw GradeTooLowException();
		return;
	}
	else if (grade < GRADE_LIMIT_HIGH)
	{
		throw GradeTooHighException();
		return;
	}
	std::cout << "Bureaucrat Created.\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& instance)
	: name(instance.name)
	, grade(instance.grade)
{
	std::cout << "Bureaucrat Created.\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& instance)
{
	grade = instance.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat Destroyed.\n";
}

const std::string& Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::upGrade()
{
	if (grade == GRADE_LIMIT_HIGH)
		throw GradeTooHighException();
	else
		--grade;
}

void Bureaucrat::downGrade()
{
	if (grade == GRADE_LIMIT_LOW)
		throw GradeTooLowException();
	else
		++grade;
}

// ----- inner class -----

void Bureaucrat::GradeTooHighException::report()
{
	std::cerr << "grade is too high\n";
}

void Bureaucrat::GradeTooLowException::report()
{
	std::cerr << "grade is too low\n";
}

// ----- extern -----

std::ostream& operator<<(std::ostream& os, const Bureaucrat& instance)
{
	std::cout << instance.getName() << ", bureaucrat grade " << instance.getGrade() << ".\n";
	return (os);
}
