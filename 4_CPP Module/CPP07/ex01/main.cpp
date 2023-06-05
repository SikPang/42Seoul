/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:59:25 by kwsong            #+#    #+#             */
/*   Updated: 2023/06/05 13:02:37 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "iter.hpp"

#define ARR_SIZE 10

struct Temp
{
public:
	int val;

public:
	Temp()
		: val(42)
	{
	}
};

std::ostream& operator<<(std::ostream& os, const Temp& temp)
{
	os << temp.val;
	return os;
}

int main()
{
	std::string	sArr[ARR_SIZE] = {"hello", "world", "my", "name", "is", "kwsong"};
	int			iArr[ARR_SIZE] = {1, 2, 3, 4, 5};
	float		fArr[ARR_SIZE] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	char		cArr[ARR_SIZE] = {'h', 'e', 'l', 'l', 'o'};
	long		lArr[ARR_SIZE] = {1, 2, 3, 4, 5};
	Temp		tArr[ARR_SIZE] = {};

	iter(sArr, ARR_SIZE, print);
	std::cout << "\n";

	iter(iArr, ARR_SIZE, print);
	std::cout << "\n";

	iter(fArr, ARR_SIZE, print);
	std::cout << "\n";

	iter(cArr, ARR_SIZE, print);
	std::cout << "\n";

	iter(lArr, ARR_SIZE, print);
	std::cout << "\n";

	iter(tArr, ARR_SIZE, print);
	std::cout << "\n";

	return 0;
}