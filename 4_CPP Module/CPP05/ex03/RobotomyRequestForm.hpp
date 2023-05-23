/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:41:28 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/23 20:46:16 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <random>

class RobotomyRequestForm : public AForm
{
private:
	const std::string target;

private:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

public:
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();
	void execute(Bureaucrat const & executor) const; // override
};
