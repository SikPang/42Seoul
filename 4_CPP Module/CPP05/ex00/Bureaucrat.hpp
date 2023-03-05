/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:18:26 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/17 15:15:34 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>

#define GRADE_LIMIT_MAX 150
#define GRADE_LIMIT_MIN 1

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(Bureaucrat& instance);
	virtual ~Bureaucrat();
	Bureaucrat&			operator=(Bureaucrat& instance);
	void				operator<<(Bureaucrat& instance);

	const std::string	getName();
	int					getGrade();
	void				upGrade();
	void				downGrade();

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

#endif