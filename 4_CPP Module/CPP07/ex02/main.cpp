/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 21:10:28 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

#include "Array.hpp"

#define MAX_VAL 750

void myTest()
{
	Array<int>			iArr1;
	Array<int>			iArr2(10);
	Array<float>		fArr(10);
	Array<char>			cArr(10);
	Array<std::string>*	sArr = new Array<std::string>(10);

	std::cout << "iArr1\n";
	for (unsigned int i=0; i<iArr1.size(); ++i)
		std::cout << i << ":" << iArr1[i] << ", ";
	std::cout << "\n\n";

	std::cout << "iArr2\n";
	for (unsigned int i=0; i<iArr2.size(); ++i)
		std::cout << i << ":" << iArr2[i] << ", ";
	std::cout << "\n\n";

	std::cout << "fArr\n";
	for (unsigned int i=0; i<fArr.size(); ++i)
		std::cout << i << ":" << fArr[i] << ' ';
	std::cout << "\n\n";

	std::cout << "cArr\n";
	for (unsigned int i=0; i<cArr.size(); ++i)
		std::cout << i << ":" << cArr[i] << ' ';
	std::cout << "\n\n";

	std::cout << "sArr\n";
	for (unsigned int i=0; i<sArr->size(); ++i)
		std::cout << i << ":" << (*sArr)[i] << ' ';
	std::cout << "\n\n";

	for (unsigned int i=0; i<sArr->size(); ++i)
		(*sArr)[i] = "test";

	std::cout << "sArr\n";
	for (unsigned int i=0; i<sArr->size(); ++i)
		std::cout << i << ":" << (*sArr)[i] << ' ';
	std::cout << "\n\n";

	Array<std::string> copy(*sArr);
	delete sArr;

	std::cout << "\ncopy\n";
	for (unsigned int i=0; i<copy.size(); ++i)
		std::cout << i << ":" << copy[i] << ' ';
	std::cout << "\n\n";
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

		 for (int i = 0; i < MAX_VAL; i++)
		{
			if (tmp[i] != numbers[i] || test[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	std::cout <<"\n\n";
	myTest();
    return 0;
}