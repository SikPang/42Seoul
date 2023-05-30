/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:19:15 by kwsong            #+#    #+#             */
/*   Updated: 2023/05/30 21:56:42 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

public:
	MutantStack();
	MutantStack(const MutantStack& other);
	~MutantStack();
	MutantStack& operator=(const MutantStack& other);

public:
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();
};

template <typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
	: std::stack<T>(other)
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>:: end()
{
	return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return std::stack<T>::c.rend();
}