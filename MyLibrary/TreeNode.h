#include "Dlist.h"


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
		DList<TreeNode*>* sons;

	public:
		TreeNode<TYPE>()
		{
			parent = new TreeNode<TYPE>();
			sons = new DList<TYPE>();
		}
		~TreeNode<TYPE>()
		{

		}





};



#endif // !Tree_H