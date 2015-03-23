#ifndef DList_H
#define DList_H

#include "ListNode.h"

template <class TYPE> class DList
{
	private:
		ListNode<TYPE>* start;
		//ListNode<TYPE>* end; // TODO Revisar que canvii el end tal com toca
		ListNode<TYPE>* iterator;
		//  TODO Const Correct. DONE
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

		void deleteNode(const ListNode<TYPE>* node)
		{
			//TODO Delete a node in DList DONE
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

		const ListNode<TYPE>* getStart()const
		{
			return start;
		}

		void add(const TYPE valor)
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
				ListNode<TYPE>* prevIterator = new ListNode<TYPE>();
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

		int count() const
		{
			ListNode<TYPE>* iterator = start;
			int i = 0;
			while (iterator->next != NULL)
			{
				iterator = iterator->next;
				i++;
			}
			return i;
		}

		int insert(const int pos)
		{
			//TODO Insert
		}

		//TODO Get node at position
		//TODO get position of node
		//TODO delete node at position

};

#endif