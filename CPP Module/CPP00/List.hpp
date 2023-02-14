/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:28:08 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/14 17:00:36 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class List
{
public:
	class Node
	{
	public:
		Node*	prev;
		Node*	next;
		T		data;

	public:
		Node();
		Node(T data);
		Node(Node& instance);
		~Node();
		Node& operator=(Node& instance);
	};

public:
	Node*	head;
	Node*	tail;
	int		size;

public:
	List();
	List(List& instance);
	~List();
	List& operator=(List& instance);

public:
	T		Front();
	T		Back();
	int		Size();
	void	PushBack(T data);
	void	PushFront(T data);
	void	PopBack();
	void	PopFront();
	void	CheckLimit();
	void	Erase(Node& target);

public:
	void	Print(List& list);
};


// ----- Outer class -----
template <typename T>
List<T>::List()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

template <typename T>
List<T>::List(List<T>& instance)
{
	head = instance.tail;
	tail = instance.tail;
	size = instance.size;
}

template <typename T>
List<T>& List<T>::operator=(List<T>& instance)
{
	head = instance.tail;
	tail = instance.tail;
	size = instance.size;
}

template <typename T>
List<T>::~List()
{
	Node* cur = head;
	Node* temp;
	
	while (cur != NULL)
	{
		temp = cur;
		cur = cur->next;
		delete temp;
	}
}

template <typename T>
T List<T>::Back()
{
	if (size == 0)
		return 0;
	return tail->data;
}

template <typename T>
T List<T>::Front()
{
	if (size == 0)
		return 0;
	return head->data;
}

template <typename T>
int List<T>::Size()
{
	return size;
}

template <typename T>
void List<T>::PushBack(T data)
{
	Node *newNode = new Node(data);

	if (size == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	++size;
}

template <typename T>
void List<T>::PushFront(T data)
{
	Node *newNode = new Node(data);

	if (size == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	++size;
}

template <typename T>
void List<T>::PopBack()
{
	Node* temp = tail;
	
	if (size == 0)
		return;
	else if (size == 1)
	{
		tail = NULL;
		head = NULL;
	}
	else
	{
		tail->prev->next = NULL;
		tail = tail->prev;
	}
	delete temp;
	--size;
}

template <typename T>
void List<T>::PopFront()
{
	Node* temp = head;

	if (size == 0)
		return;
	else if (size == 1)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		head->next->prev = NULL;
		head = head->next;
	}
	delete temp;
	--size;
}

template <typename T>
void List<T>::Erase(Node& target)
{
	if (size == 0)
		return;

	if (&target == &head)
		PopFront();
	else if (&target == &tail)
		PopBack();

	Node* temp = &head;
	
	while (temp != NULL)
	{
		if (temp == &target)
			break;
		temp = &(temp->next);
	}

	if (temp == NULL)
		return;
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		--size;
	}
}


// ----- Inner class -----
template <typename T>
List<T>::Node::Node()
{
	prev = NULL;
	next = NULL;
	data = NULL;
}

template <typename T>
List<T>::Node::Node(T data)
{
	prev = NULL;
	next = NULL;
	this->data = data;
}

template <typename T>
List<T>::Node::Node(Node& instance)
{
	prev = instance.prev;
	next = instance.next;
	data = instance.data;
}

template <typename T>
typename List<T>::Node& List<T>::Node::operator=(Node& instance)
{
	prev = instance.prev;
	next = instance.next;
	data = instance.data;
}

template <typename T>
List<T>::Node::~Node()
{
	//delete this;
}