#define _CRT_SECURE_NO_WARNINGS 1


#include "BinarySearchTree.h"

void TestBSTree1()
{
	BSTree<int> t;
	int a[] = { 8, 3, 7, 2, 5, 6, 6,0,-1 };
	for (auto e : a)
	{
		t.Insert(e);
	}

	// ≈≈–Ú + »•÷ÿ
	t.InOrder();

	t.Erase(3);
	t.InOrder();

	t.Erase(6);
	t.InOrder();

	for (auto e : a)
	{
		t.Erase(e);
		t.InOrder();
	}
}


int main()
{
	TestBSTree1();

	return 0;
}