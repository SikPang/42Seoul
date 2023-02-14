/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:16:02 by kwsong            #+#    #+#             */
/*   Updated: 2023/02/14 17:03:15 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iostream>
#include "List.hpp"

using namespace std;

void f()
{
	system("leaks a.out");
}

void Print(List<int>& list)
{
	cout << "- size : " << list.Size();
	cout << ", front : " << list.Front();
	cout << ", back : " << list.Back() << '\n';

	List<int>::Node* temp = list.head;
	while (temp != NULL)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << "\n\n";
}

void Print(List<string>& list)
{
	cout << "- size : " << list.Size();
	cout << ", front : " << list.Front();
	cout << ", back : " << list.Back() << '\n';

	List<string>::Node* temp = list.head;
	while (temp != NULL)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << "\n\n";
}

int main()
{
	atexit(f);
	List<int> list;
	
	Print(list);
	for (int i=0; i<5; ++i)
	{
		list.PushBack(i + 1);
		Print(list);
	}
	for (int i=0; i<5; ++i)
	{
		list.PopBack();
		Print(list);
	}

	for (int i=0; i<5; ++i)
	{
		list.PushFront(i + 1);
		Print(list);
	}
	for (int i=0; i<5; ++i)
	{
		list.PopFront();
		Print(list);
	}

	List<string> strList;
	
	Print(strList);
	string temp = "no.0";
	for (int i=0; i<5; ++i)
	{
		temp[3] += 1;
		strList.PushBack(temp);
		Print(strList);
	}
	for (int i=0; i<5; ++i)
	{
		strList.PopBack();
		Print(strList);
	}

	temp = "no.0";
	for (int i=0; i<5; ++i)
	{
		temp[3] += 1;
		strList.PushFront(temp);
		Print(strList);
	}
	for (int i=0; i<5; ++i)
	{
		strList.PopFront();
		Print(strList);
	}
}

// void Print(list<int>& list)
// {
// 	cout << list.size() << '\n';
// 	cout << list.front() << '\n';
// 	cout << list.back() << '\n' << '\n';
// }

// int main()
// {
// 	list<int> list;

// 	Print(list);

// 	for (int i=0; i<5; ++i)
// 	{
// 		list.push_back(i + 1);
// 		Print(list);
// 	}
// }