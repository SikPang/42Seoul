/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:03:06 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/26 15:55:28 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

template <typename T>
class Array
{
private:
	T*				arr;
	unsigned int	capacity;

public:
	Array();
	Array(unsigned int n);
	Array(const Array& instance);
	virtual ~Array();
	Array& operator=(const Array& instance);
	T& operator[](unsigned int index);
	unsigned int size() const;

public:
	class LengthException : public std::exception 
	{
	// public:
	// 	const char* what() const// override
	// 	{
	// 		return "out of index\n";
	// 	}
	};
};

// template <typename T>
// const char* Array<T>::LengthException::what() const
// {
// 	return "out of index\n";
// }

// 1로?? NULL로??
template <typename T>
Array<T>::Array()
	: arr(new T[1]())
	, capacity(1)
{
	std::cout << "Array [1] Created.\n";
}

template <typename T>
Array<T>::Array(unsigned int n)
	: arr(new T[n]())
	, capacity(n)
{
	std::cout << "Array [" << n << "] Created.\n";
}

template <typename T>
Array<T>::Array(const Array<T>& instance)
	: arr(new T[instance.capacity])
	, capacity(instance.capacity)
{
	for (unsigned int i = 0; i < capacity; ++i)
		arr[i] = instance.arr[i];

	std::cout << "Array [" << instance.capacity << "] Created.\n";
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& instance)
{
	if (&instance == this)
		return *this;

	delete[] arr;
	arr = new T[instance.capacity]();
	capacity = instance.capacity;
	for (unsigned int i = 0; i < capacity; ++i)
		arr[i] = instance.arr[i];
	
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= capacity)
		throw LengthException();

	return arr[index];
}

template <typename T>
Array<T>::~Array() 
{
	delete[] arr;
	std::cout << "Array Destroyed.\n";
}

template <typename T>
unsigned int Array<T>::size() const
{
	return capacity;
}