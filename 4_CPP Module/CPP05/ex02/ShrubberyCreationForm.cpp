/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:29:44 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/24 14:42:43 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137)
	, target("")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137)
	, target(target)
{
	(void)target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
	, target(other.target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	
	std::ofstream destFile(target + "_shrubbery");

	if (destFile.fail())
		return;

	destFile << "              \n";
	destFile << "      @@@     \n";
	destFile << "    @@@#@@@   \n";
	destFile << "   @@#@#@#@@  \n";
	destFile << "    @@###@@   \n";
	destFile << "      @#@     \n";
	destFile << "       #      \n";
	destFile << "       #      \n";
	destFile << "       #      \n";
	destFile << "       #      \n";
}