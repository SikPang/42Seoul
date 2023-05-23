/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/23 20:23:58 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat b1;
	Bureaucrat b2("kim", 1);
	Bureaucrat b3("lee", 150);

	Form f1;
	Form f2("form2", 1, 1);
	Form f3("form3", 150, 150);
	
	std::cout << b1 << b2 << b3 << f1 << f2 << f3;
	std::cout << "\n-----\n\n";

	b3.signForm(f1);
	b3.signForm(f2);
	b3.signForm(f3);

	std::cout << "\n-----\n\n";
	
	b1.signForm(f1);
	b1.signForm(f2);
	b1.signForm(f3);

	std::cout << "\n-----\n\n";

	b2.signForm(f1);
	b2.signForm(f2);
	b2.signForm(f3);

	std::cout << "\n-----\n\n";

	return 0;
}