/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:28:08 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/13 22:47:11 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class List
{
private:
	class Node
	{
	private:
		Node&	prevNode;
		Node&	nextNode;
		T		data;

	public:
		Node();
		Node(T data);
		Node(Node& instance);
		~Node();
		Node& operator=(Node& instance);
	};

private:
	Node&	head;
	Node&	tail;
	int		size;

public:
	List();
	List(List& instance);
	~List();
	List& operator=(List& instance);
};

template <typename T>
List<T>::Node::Node()
{
	prevNode = NULL;
	nextNode = NULL;
	data = NULL;
}

