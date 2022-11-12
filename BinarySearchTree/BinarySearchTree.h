#pragma once

#include <iostream>
using namespace std;

template<class K> // Kay
struct BSTreeNode  // 公开
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	BSTreeNode(const K& key) // 构造
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}

};

template<class K> 
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(const K& key) // 插入节点
	{
		if (_root == nullptr)
		{
			_root = new Node(key); // 整棵树为空
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)  // 找到空为止
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;  // 不允许相同的key插入
			}
		}

		// cur为空，插入+链接父节点
		cur = new Node(key);
		if (parent->_key > key)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		return true;
	}

	bool Erase(const K& key) // 删除节点
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				// key与_key相等，开始删除
				// 1、左为空
				// 2、右为空
				// 3、左右都不为空
				if (cur->_left == nullptr)  // 1
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					delete cur;
					cur = nullptr;
				}
				else if (cur->_right == nullptr) // 2
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
					delete cur;
					cur = nullptr;
				}
				else  // 3
				{
					// 替换法删除
					// 找到右子树中最小节点进行替换
					Node* minParent = cur;
					Node* min = cur->_right;
					while (min->_left)
					{
						minParent = min;
						min = min->_left;
					}

					swap(cur->_key, min->_key);
					if (minParent->_left == min)  
						minParent->_left = min->_right;
					else
						minParent->_right = min->_right;

					delete min;
				}

				return true;
			}
		}

		return false;
	}

	void InOrder() // 套用，为了无参 + 调用私有的_root
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	void _InOrder(Node* root) // 中序打印
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root = nullptr; // 缺省为空
};