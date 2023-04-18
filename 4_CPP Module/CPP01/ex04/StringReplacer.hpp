/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:43:40 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/18 19:57:04 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __STRINGREPLACER_HPP__
#define __STRINGREPLACER_HPP__

#include <fstream>
#include <string>

class StringReplacer
{
private:
	std::string		fileName;
	std::string		targetString;
	std::string		destString;
	std::ifstream	targetFile;
	std::ofstream	destFile;

public:
	StringReplacer(char* fileName, char* targetString, char* destString);

public:
};

#endif