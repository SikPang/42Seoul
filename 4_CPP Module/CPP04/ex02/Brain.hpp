/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:47:55 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 19:29:53 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <string>

#define IDEA_CAPACITY 100

class Brain
{
protected:
	std::string	ideas[IDEA_CAPACITY];

public:
	Brain();
	Brain(Brain& instance);
	virtual ~Brain();
	Brain&			operator=(Brain& instance);
};

#endif