/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:43:33 by kwsong            #+#    #+#             */
/*   Updated: 2023/04/18 19:56:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplacer.hpp"

StringReplacer::StringReplacer(char* fileName, char* targetString, char* destString)
{
	this->fileName = fileName;
	this->targetString = targetString;
	this->destString = destString;
	targetFile = std::ifstream(this->fileName);
	destFile = std::ofstream(this->fileName + ".replace");
}