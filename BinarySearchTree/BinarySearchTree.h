#pragma once

#include <iostream>
using namespace std;

template<class K> // Kay
struct BSTreeNode  // ����
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	BSTreeNode(const K& key) // ����
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
	bool Insert(const K& key) // ����ڵ�
	{
		if (_root == nullptr)
		{
			_root = new Node(key); // ������Ϊ��
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)  // �ҵ���Ϊֹ
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
				return false;  // ��������ͬ��key����
			}
		}

		// curΪ�գ�����+���Ӹ��ڵ�
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

	bool Erase(const K& key) // ɾ���ڵ�
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
				// key��_key��ȣ���ʼɾ��
				// 1����Ϊ��
				// 2����Ϊ��
				// 3�����Ҷ���Ϊ��
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
					// �滻��ɾ��
					// �ҵ�����������С�ڵ�����滻
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

	void InOrder() // ���ã�Ϊ���޲� + ����˽�е�_root
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	void _InOrder(Node* root) // �����ӡ
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root = nullptr; // ȱʡΪ��
};