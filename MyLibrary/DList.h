#ifndef DList_H
#define DList_H

#include "ListNode.h"

template <class T> class DList
{
	public:
		ListNode<T>* start;
		ListNode<T>* end;
		ListNode<T>* iterator;
		//  Bla.
		
		DList()
		{
			start = NULL;
			end = NULL;
			iterator = NULL;
		}

		~DList()
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
			//TODO Delete a node in DList
			// bla bla delete something;	
		}

		void add(T valor)
		{
			ListNode<T>* newNode = new ListNode<T>();
			newNode->val = valor;
			newNode->next = NULL;
			newNode->previous = NULL;

			if (start == NULL)
			{
				start = new ListNode<T>();
				start = newNode;				
			}
			else
			{
				ListNode<T>* prevIterator = new ListNode<T>();
				while (iterator->next != NULL)
				{
					prevIterator = iterator;
					iterator = iterator->next;
				}
				iterator->next = newNode;
				iterator->previous = prevIterator; // Arreglar
			}

			end = iterator; // Start bla bla 
			iterator = start;
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