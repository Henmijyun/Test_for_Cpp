/*#include <iostream>

using namespace std;

// ����ָ�룺
// 1������RAII˼�����delete��Դ����
// 2����ָ��һ������Ϊ
// 3�����Ǵ��ڿ�������
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};


//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("��0����");
//
//	return a / b;
//}
//
////void Func()
////{
////	// 1�����p1����new ���쳣����Σ� 
////	// 2�����p2����new ���쳣����Σ�
////	// 3�����div���������ֻ����쳣����Σ�    �����ڴ�й¶
////	int* p1 = new int;
////	int* p2 = new int;
////
////	cout << div() << endl;
////
////	delete p1;
////	delete p2;
////	cout << "�ͷ���Դ" << endl;
////}
//
//void Func()
//{
//	// 1�����p1����new ���쳣����Σ� 
//	// 2�����p2����new ���쳣����Σ�
//	// 3�����div���������ֻ����쳣����Σ�   ���������򣬻������쳣�������������
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(new int);
//
//	*sp1 = 0;
//	*sp2 = 2;
//
//	cout << div() << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}





class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}
	//private:
	int _a1 = 0;
	int _a2 = 0;
};

// C++98
// auto_ptr  ��Դ����Ȩת�ƣ��������εĿ������ᵼ�±�������������
// auto_ptr  �������������ڳ������ϣ��ܶ๫˾��ȷҪ����ʹ����

// boost     // boost����C++��׼ίԱ���Ա������
// scoped_ptr
// shared_ptr
// weak_ptr

// C++11    // ��boost��ҵ
// unique_ptr 
// shared_ptr
// weak_ptr

int main()
{
	auto_ptr<A> ap1(new A);   // ���е�auto_ptr��������
	ap1->_a1++;
	ap1->_a2++;
	// �������⣺
	auto_ptr<A> ap2(ap1);   // �൱����Դת�ƣ�ap1���ɿ�ָ�룬�ǲ������εĿ���
	ap1->_a1++;
	ap1->_a2++;


	SmartPtr<A> sp1(new A); // �Լ�ʵ�ֵ�Ҳ��������
	sp1->_a1++;
	sp1->_a2++;
	// �������⣺
	//SmartPtr<A> sp2(sp1);  // err ǳ������ָ��ָ��ͬһ��ռ�

	return 0;
}

*/



// ����ָ��
#include <iostream>
#include <string>
#include <memory>


using namespace std;

#include "SmartPtr.h"

int main()
{
	// test_auto_ptr();
	
	// test_unique_ptr();
	
	// test_shared_ptr1();

	test_shared_ptr2();
	
	
	return 0;
}