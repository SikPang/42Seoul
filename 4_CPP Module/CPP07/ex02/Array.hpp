/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:03:06 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/16 21:08:15 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template <typename T>
class Array
{
private:
	T*				arr;
	unsigned int	size;

public:
	Array();
	Array(unsigned int n);
	Array(Array& instance);
	virtual ~Array();
	Array&			operator=(Array& instance);
	T&				operator[](unsigned int index);

	unsigned int	Size();
};

// 1로?? NULL로??
template <typename T>
Array<T>::Array()
{
	arr = new T();
	size = 1;

	std::cout << "Array [1] Created.\n";
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	arr = new T[n]();
	size = n;

	std::cout << "Array [" << n << "] Created.\n";
}

template <typename T>
Array<T>::Array(Array<T>& instance)
{
	arr = new T[instance.size]();
	size = instance.size;
	for (int i=0; i<size; ++i)
		arr[i] = instance.arr[i];

	std::cout << "Array [" << instance.size << "] Created.\n";
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>& instance)
{
	arr = new T[instance.size]();
	size = instance.size;
	for (int i=0; i<size; ++i)
		arr[i] = instance.arr[i];
	
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= size)
	{
		// exception
		return arr[0];
	}

	return arr[index];
}

template <typename T>
Array<T>::~Array() 
{
	delete[] arr;
	std::cout << "Array Destroyed.\n";
}

template <typename T>
unsigned int Array<T>::Size()
{
	return size;
}

#endif