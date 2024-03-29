/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/23 20:32:26 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat b1;
	Bureaucrat b2("kim", 1);
	Bureaucrat b3("lee", 150);

	PresidentialPardonForm pf("park");
	RobotomyRequestForm rf("kim");
	ShrubberyCreationForm sf("lee");
	
	std::cout << b1 << b2 << b3 << pf << rf << sf;
	std::cout << "\n-----\n\n";

	b3.executeForm(pf);
	b3.executeForm(rf);
	b3.executeForm(sf);

	b2.signForm(pf);
	b2.signForm(rf);
	b2.signForm(sf);

	std::cout << "\n-----\n\n";

	b3.executeForm(pf);
	b3.executeForm(rf);
	b3.executeForm(sf);

	std::cout << "\n-----\n\n";
	
	b1.executeForm(pf);
	b1.executeForm(rf);
	b1.executeForm(sf);

	std::cout << "\n-----\n\n";

	b2.executeForm(pf);
	b2.executeForm(rf);
	b2.executeForm(sf);

	std::cout << "\n----------\n\n";

	return 0;
}