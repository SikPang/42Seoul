/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:06 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/23 20:20:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string name;
	const int gradeForSign;
	const int gradeForExe;
	bool isSigned;

public:
	AForm();
	AForm(const std::string& name, int gradeForSign, int gradeForExe);
	AForm(const AForm& instance);
	virtual ~AForm();
	AForm& operator=(const AForm& instance);

public:
	const std::string& getName() const;
	bool getIsSiged() const;
	int getGradeForSign() const;
	int getGradeForExe() const;
	void beSigned(const Bureaucrat& bure);
	virtual void execute(Bureaucrat const & executor) const;

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

	class AlreadySigned
	{
	public:
		void	report();
	};

	class NotSigned
	{
	public:
		void	report();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& value);
