/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:41:42 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/23 20:49:11 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45)
	, target("")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45)
	, target(target)
{
	(void)target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
	, target(other.target)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void)other;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	
	std::random_device rd;
	std::mt19937 gen(rd());

	std::cout << "(drilling noises) ";
	if (gen() % 2 == 0)
		std::cout << target << " has been robotomized successfully\n";
	else
		std::cout << target << " failed to roboromized\n";
}