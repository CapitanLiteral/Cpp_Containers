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
			while (iterator) 
			{
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
		const ListNode<TYPE>* getEnd()const
		{
			ListNode<TYPE>* ret = start;
			
			while (ret->next != NULL)
			{
				ret = ret->next;
			}

			return ret;
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

		unsigned int count() const
		{
			ListNode<TYPE>* iterator = start;
			int i = 0;
			while (iterator/*->next*/ != NULL)
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

		unsigned int delNodes(const int sPos, int quantity)
		{
			ListNode<TYPE>* iterator = start;
			ListNode<TYPE>* tmp;
			ListNode<TYPE>* bFirst;
			int ret = 0;
			int i = 0;
			//DList<ListNode<TYPE>>* delList = new DList<ListNode<TYPE>>();

			for (i = 0; i < sPos; i++)
			{
				iterator = iterator->next; //Posible error
			}

			if (iterator->previous != NULL)
				bFirst = iterator->previous;
			if (quantity > count() - i)
				quantity = count() - i;

			for (int j = 0; j < quantity; j++)
			{
				tmp = iterator;
				iterator = iterator->next;
				delete tmp;
				ret++;
			}
			if (bFirst != NULL && sPos != 0)
			{
				bFirst->next = iterator;
				if (iterator != NULL)
					iterator->previous = bFirst;
			}
			else
			{
				start = iterator;
			}
				
			

			return ret;
		}

		//TODO Get node at position
		//TODO get position of node
		//TODO delete node at position

};

#endif