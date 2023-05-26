/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:35:16 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/26 14:27:59 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	uintptr_t uLong = 42;
	Data* data = new Data();
	data->data = "hello world";

	std::cout << "before : " << data->data << "\n";
	std::cout << "before : " << uLong << "\n\n";

	uintptr_t after_uLong = Serializer::serialize(Serializer::deserialize(uLong));
	Data* after_data = Serializer::deserialize(Serializer::serialize(data));

	std::cout << "after  : " << after_data->data << "\n";
	std::cout << "after  : " << after_uLong << "\n";

	delete data;
}