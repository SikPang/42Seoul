/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:18:28 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/17 15:23:39 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
:	name("someone"),
	grade(75)
{
	std::cout << "Bureaucrat Created.\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
:	name(name),
	grade(grade)
{
	if (grade > 150)
	{
		throw GradeTooLowException();
		return;
	}
	else if (grade < 1)
	{
		throw GradeTooHighException();
		return;
	}
	std::cout << "Bureaucrat Created.\n";
}

Bureaucrat::Bureaucrat(Bureaucrat& instance)
:	name(instance.name),
	grade(instance.grade)
{
	std::cout << "Bureaucrat Created.\n";
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& instance)
{
	grade = instance.grade;
	return *this;
}

void Bureaucrat::operator<<(Bureaucrat& instance)
{
	std::cout << name << ", bureaucrat grade " << grade << "\n";
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat Destroyed.\n";
}

const std::string Bureaucrat::getName()
{
	return name;
}

int Bureaucrat::getGrade()
{
	return grade;
}

void Bureaucrat::upGrade()
{
	if (grade == 1)
	{
		throw GradeTooHighException();
		return;
	}
	--grade;
}

void Bureaucrat::downGrade()
{
	if (grade == 150)
	{
		throw GradeTooLowException();
		return;
	}
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