/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:06 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/17 16:23:35 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeForSign;
	const int			gradeForExe;

public:
	AForm();
	AForm(std::string name, bool isSigned, int gradeForSign, int gradeForExe);
	AForm(AForm& instance);
	~AForm();
	AForm&			operator=(AForm& instance);
	void			operator<<(AForm& instance);

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