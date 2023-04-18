/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:43:40 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/18 22:13:57 by kwsong           ###   ########.fr       */
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
	std::string	fileName;
	std::string	targetString;
	std::string	destString;
	std::string	targetFile;
	std::string	destFile;

public:
	StringReplacer(char* fileName, char* targetString, char* destString);

private:
	void WriteToDestFile(std::ofstream& destFile, std::string& temp);
	void SplitLineAndReplace(std::string& line, std::ofstream& destFile);

public:
	bool Replace();
};

#endif