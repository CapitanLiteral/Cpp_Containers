#include "Dlist.h"
#include "ListNode.h"


#ifndef TreeNode_H
#define TreeNode_H
#pragma once
template <class TYPE>
class TreeNode
{
	private:
	public:
		TYPE data;
		TreeNode<TYPE>* parent;
		DList<TreeNode<TYPE>*> sons;

	public:
		TreeNode<TYPE>()
		{
			parent = NULL;
		}
		~TreeNode<TYPE>()
		{

		}
		void visitAll(DList<TYPE>& list)
		{
			list.add(data);
			//ListNode<TYPE>* iterator = sons->getStart();+
			for (int i = 0; i < sons.count(); i++)
			{
				sons.getAt(i)->val->visitAll(list);
			}				
		}




};



#endif // !Tree_H