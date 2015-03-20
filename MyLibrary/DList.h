#ifndef DList_H
#define DList_H

#include "ListNode.h"

template <class TYPE> class DList
{
	private:
		ListNode<TYPE>* start;
		//ListNode<TYPE>* end; // TODO Revisar que canvii el end tal com toca
		ListNode<TYPE>* iterator;
		//  TODO Const Correct.
	public:	
		DList()
		{
			start = NULL;
			//end = NULL;
			iterator = NULL;
		}

		~DList()
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
			//TODO Delete a node in DList
			// bla bla delete something;
			if (node != NULL && start != NULL)
			{
				if (node != start)
				{
					ListNode<TYPE> *iterator = start;
					while (iterator->next != node)
					{
						iterator = iterator->next;
					}

					iterator->next = node->next;
					node->next->previous = iterator;

				}
				else
					start = start->next;

				delete node;
			}
		}

		void add(TYPE valor)
		{
			ListNode<TYPE>* newNode = new ListNode<TYPE>();
			newNode->val = valor;
			newNode->next = NULL;
			newNode->previous = NULL;

			if (start == NULL)
			{
				start = new ListNode<TYPE>();
				start = newNode;				
			}
			else
			{
				ListNode<TYPE>* prevIterator  // = new ListNode<T>();
				while (iterator->next != NULL)
				{
					prevIterator = iterator;
					iterator = iterator->next;
				}
				iterator->next = newNode;
				iterator->previous = prevIterator; // Arreglar
			}

			//end = iterator; // Start bla bla 
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

		int insert(int pos)
		{
			//TODO Insert
		}

		//TODO Get node at position
		//TODO get position of node
		//TODO delete node at position

};

#endif