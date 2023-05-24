/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/24 14:47:52 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat b1;
	Bureaucrat b2("kim", 1);
	Bureaucrat b3("lee", 150);

	Intern someRandomIntern;

	AForm* pf;
	AForm* rf;
	AForm* sf;
	
	pf = someRandomIntern.makeForm("presidential pardon", "Bender");
	rf = someRandomIntern.makeForm("robotomy request", "Bender");
	sf = someRandomIntern.makeForm("shrubbery creation", "Bender");

	std::cout << b1 << b2 << b3 << *pf << *rf << *sf;
	std::cout << "\n-----\n\n";

	b3.executeForm(*pf);
	b3.executeForm(*rf);
	b3.executeForm(*sf);

	b2.signForm(*pf);
	b2.signForm(*rf);
	b2.signForm(*sf);

	std::cout << "\n-----\n\n";

	b3.executeForm(*pf);
	b3.executeForm(*rf);
	b3.executeForm(*sf);

	std::cout << "\n-----\n\n";
	
	b1.executeForm(*pf);
	b1.executeForm(*rf);
	b1.executeForm(*sf);

	std::cout << "\n-----\n\n";

	b2.executeForm(*pf);
	b2.executeForm(*rf);
	b2.executeForm(*sf);

	std::cout << "\n----------\n\n";

	delete pf;
	delete rf;
	delete sf;

	return 0;
}