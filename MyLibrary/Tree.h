#include "Dlist.h"
#include "TreeNode.h"

#ifndef Tree_H
#define Tree_H
#pragma once
template <class TYPE>
class Tree
{
	private:
		TreeNode<TYPE>* root;

	public:
		Tree(const TYPE& data)
		{
			root = new TreeNode<TYPE>();
			root->data = data;
		}
		Tree(const TreeNode<TYPE>& _root)
		{
			root = _root;
		}
		Tree()
		{
			root = new TreeNode<TYPE>();
		}
		~Tree()
		{
			delete[] root;
		}
		
		TreeNode<TYPE>* add(const TYPE & data)
		{
			TreeNode<TYPE> *son = new TreeNode<TYPE>();
			son->data = data;
			son->parent = root;
			root->sons.add(son);

			return son;
		}

		TreeNode<TYPE>* add(const TYPE& data, TreeNode<TYPE>* parent)
		{
			TreeNode<TYPE> *son = new TreeNode<TYPE>();
			son->data = data;
			son->parent = parent;
			parent->sons.add(son);
			return son;
		}

		void visitAllNodes(DList<TYPE>& list) const
		{
			root->visitAll(list);
		}




};



#endif // !Tree_H
