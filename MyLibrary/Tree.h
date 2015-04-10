#include "Dlist.h"
#include "TreeNode.h"

#ifndef Tree_H
#define Tree_H
#pragma once
template <class TYPE>
class Tree
{
	private:
		TreeNode<TYPE>& root;

	public:
		Tree()
		{
			root = new TreeNode<TYPE>();
		}
		~Tree()
		{

		}
		
		TreeNode* add(const TYPE& data)
		{
			TreeNode<TYPE> son = new TreeNode<TYPE>();
			son.data = data;
			son.parent = root;
			root.sons->add(son);

			return son;
		}

		TreeNode* add(const TYPE& data, const TreeNode& parent)
		{

		}




};



#endif // !Tree_H
