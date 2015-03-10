#include <stdio.h>

#pragma once
typedef struct node {
	int val;
	node* next;
};

class List
{
	public:
		node* start;
		node* iterator;

		List();
		~List();
		void deleteNode(node* node);

		void add(int);
		int count();
};


List::List()
{
	start = NULL;
	iterator = NULL;
}

void List::add(int valor)
{
	node* newNode = new node;
	newNode->val = valor;
	newNode->next = NULL;

	if (start == NULL)
	{
		start = new node;
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
	node* temp;
	iterator = start;
	while (iterator) {
		temp = iterator;
		iterator = temp->next;
		delete temp;
	}
}

void List::deleteNode(node* node)
{
	// bla bla delete something;	
}
