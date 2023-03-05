/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:06 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/17 16:23:33 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeForSign;
	const int			gradeForExe;

public:
	Form();
	Form(std::string name, bool isSigned, int gradeForSign, int gradeForExe);
	Form(Form& instance);
	~Form();
	Form&			operator=(Form& instance);
	void			operator<<(Form& instance);

	std::string		getName();
	bool			getIsSiged();
	int				getGradeForSign();
	int				getGradeForExe();
	void			beSigned(Bureaucrat& bure);

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