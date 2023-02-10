/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:43:50 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/10 18:52:02 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Megaphone.hpp"

Megaphone::Megaphone()
{
	str = "";
}

Megaphone::~Megaphone()
{
	//delete str;
}

Megaphone::Megaphone(const Megaphone &instance)
{
	str = "";
}

// Megaphone& Megaphone::operator= (const Megaphone &instance);
// {

// }
