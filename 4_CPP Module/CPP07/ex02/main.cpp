/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/05 13:18:42 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

#include "Array.hpp"

#define MAX_VAL 750
#define ARR_SIZE 10

template <typename T>
void myTest(T& container, const std::string& name)
{
	std::cout << "* " << name << "\n";
	for (unsigned int i=0; i<container.size(); ++i)
		std::cout << i << ":" << container[i] << ", ";
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
        std::cerr << e.what();
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	std::cout <<"\n";
	
	// my test

	Array<int>			iArr1;
	myTest(iArr1, "iArr1");

	Array<int>			iArr2(ARR_SIZE);
	myTest(iArr2, "iArr2");

	Array<float>		fArr(ARR_SIZE);
	for (int i = 0; i < ARR_SIZE; ++i)
		fArr[i] = 4.2f;
	myTest(fArr, "fArr");

	Array<char>			cArr(ARR_SIZE);
	myTest(cArr, "cArr");

	Array<std::string>*	sArr = new Array<std::string>(ARR_SIZE);
	for (int i = 0; i < ARR_SIZE; ++i)
		(*sArr)[i] = "hi";
	myTest(*sArr, "sArr");
	
	Array<std::string> copy(*sArr);
	myTest(copy, "copy");	

	delete sArr;
    return 0;
}