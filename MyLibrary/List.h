#ifndef List_H
#define List_H

#include <stdio.h>
#include "ListNode.h"



template <class TYPE> class List
{
	public:
		ListNode<TYPE>* start;
		ListNode<TYPE>* iterator;

		List()
		{
			start = NULL;
			iterator = NULL;
		}

		~List()
		{
			ListNode<TYPE>* temp;
			iterator = start;
			while (iterator) {
				temp = iterator;
				iterator = temp->next;
				delete temp;
			}
		}
		void deleteNode(ListNode<TYPE>* node)
		{
			//TODO Delete a node in the list
			// bla bla delete something;	
		}

		void add(TYPE valor)
		{
			ListNode<TYPE>* newNode // = new ListNode<TYPE>;
			newNode->val = valor;
			newNode->next = NULL;

			if (start == NULL)
			{
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

#endif

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
}
void List::deleteNode(node* node)
{
	// bla bla delete something;	
}*/
