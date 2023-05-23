/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:29:42 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/23 20:50:38 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string target;

private:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

public:
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const & executor) const; // override
};
