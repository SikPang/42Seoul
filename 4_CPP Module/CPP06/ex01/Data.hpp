/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:36:27 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/17 17:41:16 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DATA_HPP__
#define __DATA_HPP__

struct Data
{
	int		iData;
	float	fData;
	double	dData;

	Data()
	{
		iData = 42;
		fData = 42;
		dData = 42;
	}
};

#endif