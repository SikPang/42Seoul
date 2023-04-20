/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:43:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/20 14:12:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplacer.hpp"

StringReplacer::StringReplacer(char* fileName, char* targetString, char* destString)
{
	this->fileName = fileName;
	this->targetString = targetString;
	this->destString = destString;
	this->targetFile = this->fileName;
	this->destFile = this->fileName + ".replace";
}

void StringReplacer::WriteToDestFile(std::ofstream& destFile, std::string& temp)
{
	if (temp == targetString)
	{
		destFile << destString;
		temp = "";
	}
	else
	{
		destFile << temp[0];
		temp.erase(0, 1);
	}
}

void StringReplacer::SplitLineAndReplace(std::string& line, std::ofstream& destFile)
{
	std::string temp = "";
	
	for (size_t i = 0; i < line.size(); ++i)
	{
		temp += line[i];

		if (temp.size() == targetString.size())
			WriteToDestFile(destFile, temp);
	}
	if (temp == targetString)
		destFile << destString;
	else
		destFile << temp;
}

bool StringReplacer::Replace()
{
	std::ifstream targetFile(this->targetFile);
	std::ofstream destFile(this->targetFile + ".replace");
	
	if (targetFile.fail())
		return false;

	while (!targetFile.eof())
	{
		std::string	line;

		getline(targetFile, line);

		if (targetFile.eof())
		{
			destFile << line;
			break;
		}
		line += "\n";

		SplitLineAndReplace(line, destFile);
	}

	return true;
}