/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:50:18 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/10 19:02:32 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MEGAPHONE_H__
#define __MEGAPHONE_H__

#include <string>
#include <iostream>

class Megaphone
{
private:
	string str;

public:
	Megaphone(void);
	~Megaphone(void);
	void print_str();
};

#endif