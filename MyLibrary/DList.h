#ifndef DList_H
#define DList_H

#include <assert.h>
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
		ListNode<TYPE>* getAt(int pos) const
		{
			ListNode<TYPE>* iterator = start;
			int i = 0;
			while (i != pos)
			{
				iterator = iterator->next;
				i++;
			}
			return iterator;
		}
		//TODO delete node at position
		const TYPE& operator[] (const unsigned int index) const
		{
			assert(index < count()+1);
			ListNode<TYPE>* it = start;
			for (int i = 0; i < index; i++)
			{
				it = it->next;
			}
			return it->val;
		}
		TYPE& operator[] (const unsigned int index)
		{
			assert(index < count()+1);
			ListNode<TYPE>* it = start;
			for (int i = 0; i < index; i++)
			{
				it = it->next;
			}
			return it->val;
		}

		int orderList(bool way = true)
		{
			int iterations = 0;
			bool ordered = true;
			ListNode<TYPE>* it /*= start*/;

			for (int j = 0; j < count(); j++)
			{
				it = start;
				for (int i = 0; i < count()-j; i++)
				{
					if (way)
					{
						if (it->val > it->next->val)
						{
							swapNode(it, it->next);
							ordered = false;
						}

					}
					else
					{
						if (it->val < it->next->val)
						{
							swap(it->val, it->next->val);
							ordered = false;
						}

					}
					it = it->next;
					iterations++;
				}
				if (ordered)
					return iterations;
			}
			return iterations;
		}

		void swapNode(ListNode<TYPE>* a, ListNode<TYPE>* b)
		{
			//TODO: Acabar
			ListNode<TYPE> tmpB;
			ListNode<TYPE> tmpA;
			tmpB = *b;
			tmpA = *a;

			a->previous->next = b;
			b->next->previous = a;


			a->next = b->next;
			a->previous = b->previous;

			b->next = tmpA.next;
			b->previous = tmpA.previous;

		}








};

#endif