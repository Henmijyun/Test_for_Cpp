/*#include <iostream>

using namespace std;

// 智能指针：
// 1、利用RAII思想设计delete资源的类
// 2、像指针一样的行为
// 3、但是存在拷贝问题
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
//		throw invalid_argument("除0错误");
//
//	return a / b;
//}
//
////void Func()
////{
////	// 1、如果p1这里new 抛异常会如何？ 
////	// 2、如果p2这里new 抛异常会如何？
////	// 3、如果div调用这里又会抛异常会如何？    都会内存泄露
////	int* p1 = new int;
////	int* p2 = new int;
////
////	cout << div() << endl;
////
////	delete p1;
////	delete p2;
////	cout << "释放资源" << endl;
////}
//
//void Func()
//{
//	// 1、如果p1这里new 抛异常会如何？ 
//	// 2、如果p2这里new 抛异常会如何？
//	// 3、如果div调用这里又会抛异常会如何？   出了作用域，或者抛异常，都会调用析构
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
// auto_ptr  资源管理权转移，不负责任的拷贝，会导致被拷贝对象悬空
// auto_ptr  多年以来被挂在耻辱柱上，很多公司明确要求不能使用它

// boost     // boost库是C++标准委员会成员成立的
// scoped_ptr
// shared_ptr
// weak_ptr

// C++11    // 抄boost作业
// unique_ptr 
// shared_ptr
// weak_ptr

int main()
{
	auto_ptr<A> ap1(new A);   // 库中的auto_ptr正常调用
	ap1->_a1++;
	ap1->_a2++;
	// 拷贝问题：
	auto_ptr<A> ap2(ap1);   // 相当于资源转移，ap1会变成空指针，是不负责任的拷贝
	ap1->_a1++;
	ap1->_a2++;


	SmartPtr<A> sp1(new A); // 自己实现的也正常调用
	sp1->_a1++;
	sp1->_a2++;
	// 拷贝问题：
	//SmartPtr<A> sp2(sp1);  // err 浅拷贝，指针指向同一块空间

	return 0;
}

*/



// 智能指针
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