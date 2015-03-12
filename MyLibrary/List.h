#include <stdio.h>
#include "ListNode.h"

#pragma once

template <class T> class List
{
	public:
		ListNode<T>* start;
		ListNode<T>* iterator;

		List()
		{
			start = NULL;
			iterator = NULL;
		}

		~List()
		{
			ListNode<T>* temp;
			iterator = start;
			while (iterator) {
				temp = iterator;
				iterator = temp->next;
				delete temp;
			}
		}
		void deleteNode(ListNode<T>* node)
		{
			// bla bla delete something;	
		}

		void add(T valor)
		{
			ListNode<T>* newNode = new ListNode<T>;
			newNode->val = valor;
			newNode->next = NULL;

			if (start == NULL)
			{
				start = new ListNode<T>;
				start = newNode;
				iterator = start;
			}
			else
			{
				while (iterator->next != NULL)
					iterator = iterator->next;
				iterator->next = newNode;
				iterator = start;
			}
		}

		int count()
		{
			int i = 0;
			while (iterator->next != NULL)
			{
				iterator = iterator->next;
				i++;
			}
			return i;
		}
};


/*List::List()
{
	start = NULL;
	iterator = NULL;
}

void List::add(int valor)
{
	ListNode* newNode = new ListNode;
	newNode->val = valor;
	newNode->next = NULL;

	if (start == NULL)
	{
		start = new ListNode;
		start = newNode;
		iterator = start;
	}
	else
	{
		while (iterator->next != NULL)
			iterator = iterator->next;
		iterator->next = newNode;
		iterator = start;
	}
}

int List::count()
{
	int i = 0;
	while (iterator->next != NULL)
	{
		iterator = iterator->next;
		i++;
	}
	return i;
}
List::~List()
{
<<<<<<< HEAD
	ListNode* temp;
=======
	node* temp;
>>>>>>> origin/master
	iterator = start;
	while (iterator) {
		temp = iterator;
		iterator = temp->next;
		delete temp;
	}
}

<<<<<<< HEAD
void List::deleteNode(ListNode* node)
{
	// bla bla delete something;	
}*/
=======
void List::deleteNode(node* node)
{
	// bla bla delete something;	
}
>>>>>>> origin/master
