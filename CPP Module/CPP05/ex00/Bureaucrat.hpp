/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:18:26 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 21:23:18 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;

public:
	Bureaucrat();
	Bureaucrat(Bureaucrat& instance);
	virtual ~Bureaucrat();
	Bureaucrat&	operator=(Bureaucrat& instance);
};

#endif