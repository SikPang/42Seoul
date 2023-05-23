/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:18:26 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/23 19:21:35 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define GRADE_LIMIT_LOW 150
#define GRADE_LIMIT_HIGH 1

class Form;

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& instance);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& instance);

public:
	const std::string& getName() const;
	int getGrade() const;
	void upGrade();
	void downGrade();
	void signForm(Form& form);

public:
	class GradeTooHighException
	{
	public:
		void	report();
	};

	class GradeTooLowException
	{
	public:
		void	report();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& value);
