/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:18:28 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 21:23:17 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat Created.\n";
}

Bureaucrat::Bureaucrat(Bureaucrat& instance)
{
	std::cout << "Bureaucrat Created.\n";
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& instance)
{
	return *this;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat Destroyed.\n";
}