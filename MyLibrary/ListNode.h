


#ifndef ListNode_H
#define ListNode_H

template <class T> class ListNode
{
public:
	ListNode(){}
	~ListNode()
	{
		/*delete val;
		delete next;
		delete prevoius;*/
	}
	T val;
	ListNode<T>* next;
	ListNode<T>* previous;

private:
	
};

#endif
/*
ListNode::ListNode()
{
}

ListNode::~ListNode()
{
}*/